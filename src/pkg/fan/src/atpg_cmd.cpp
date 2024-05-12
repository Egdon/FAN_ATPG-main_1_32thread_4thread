// **************************************************************************
// File       [ atpg_cmd.cpp ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2011/09/28 created ]
// **************************************************************************
#include <future>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "core/pattern.h"
#include "atpg_cmd.h"
#include "core/pattern_rw.h"
#include "core/simulator.h"

using namespace CommonNs;
using namespace IntfNs;
using namespace CoreNs;
using namespace FanNs;

double rtime;

ReadPatCmd::ReadPatCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("read patterns");
	optMgr_.setDes("read pattern form FILE");
	optMgr_.regArg(new Arg(Arg::REQ, "pattern file", "FILE"));
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::BOOL, "verbose on. Default is off", "");
	opt->addFlag("v");
	opt->addFlag("verbose");
	optMgr_.regOpt(opt);
}
ReadPatCmd::~ReadPatCmd() {}

bool ReadPatCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR ReadPatCmd::exec(): circuit needed\n";
		return false;
	}

	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR ReadPatCmd::exec(): pattern file needed\n";
		return false;
	}

	// create pattern and pattern builder
	delete fanMgr_->pcoll;
	fanMgr_->pcoll = new PatternProcessor;
	// fanMgr_->pcoll_1 = new PatternProcessor;

	PatFile *patBlder = new PatternReader(fanMgr_->pcoll, fanMgr_->cir);

	// PatFile *patBlder_1 = new PatternReader(fanMgr_->pcoll_1, fanMgr_->cir_1);
	

	// read pattern
	fanMgr_->tmusg.periodStart();
	std::cout << "#  Reading pattern ...\n";
	bool verbose = optMgr_.isFlagSet("v");

	// std::string newPatternFilePath = "pat/FAN_s38584_1.pat";
	
	//此处newPatternFilePath 和 optMgr_.getParsedArg(0)的地址格式可能不同

	if (!patBlder->read(optMgr_.getParsedArg(0).c_str(), verbose) )
	{
		std::cerr << "**ERROR ReadPatCmd()::exec(): pattern builder error\n";
		delete fanMgr_->pcoll;
		delete patBlder;
		fanMgr_->pcoll = NULL;
		patBlder = NULL;
		return false;
	}

	TmStat stat;
	fanMgr_->tmusg.getPeriodUsage(stat);
	std::cout << "#  Finished reading pattern `" << optMgr_.getParsedArg(0) << "'";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB\n";

	delete patBlder;
	patBlder = NULL;
	return true;
}

ReportPatCmd::ReportPatCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("report pattern");
	optMgr_.setDes("report pattern information");
	Arg *arg = new Arg(Arg::REQ_INF, "pattern number to be reported", "NUM");
	optMgr_.regArg(arg);
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::BOOL, "don't print order information", "");
	opt->addFlag("disable-order");
	optMgr_.regOpt(opt);
}
ReportPatCmd::~ReportPatCmd() {}

bool ReportPatCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->pcoll)
	{
		std::cerr << "**ERROR ReportPatCmd::exec(): pattern needed\n";
		return false;
	}

	std::cout << "#  pattern information\n";
	std::cout << "#    number of pattern: " << fanMgr_->pcoll->patternVector_.size() << "\n";
	if (!optMgr_.isFlagSet("disable-order"))
	{
		std::cout << "#    pi order: ";
		for (int i = 0; i < fanMgr_->pcoll->numPI_; ++i)
		{
			std::cout << " " << fanMgr_->pcoll->pPIorder_[i];
		}
		std::cout << "\n";
		std::cout << "#    ppi order:";
		for (int i = 0; i < fanMgr_->pcoll->numPPI_; ++i)
		{
			std::cout << " " << fanMgr_->pcoll->pPPIorder_[i];
		}
		std::cout << "\n";
		std::cout << "#    po order: ";
		for (int i = 0; i < fanMgr_->pcoll->numPO_; ++i)
		{
			std::cout << " " << fanMgr_->pcoll->pPOorder_[i];
		}
		std::cout << "\n";
	}
	std::cout << "#\n";

	for (int i = 0; i < (int)fanMgr_->pcoll->patternVector_.size(); ++i)
	{
		std::cout << "#    pattern " << i << "\n";
		std::cout << "#      pi1: ";
		if (!fanMgr_->pcoll->patternVector_[i].PI1_.empty())
		{
			for (int j = 0; j < fanMgr_->pcoll->numPI_; ++j)
			{
				printValue(fanMgr_->pcoll->patternVector_[i].PI1_[j]);
			}
		}
		std::cout << "\n";
		std::cout << "#      pi2: ";
		if (!fanMgr_->pcoll->patternVector_[i].PI2_.empty())
		{
			for (int j = 0; j < fanMgr_->pcoll->numPI_; ++j)
			{
				printValue(fanMgr_->pcoll->patternVector_[i].PI2_[j]);
			}
		}
		std::cout << "\n";
		std::cout << "#      ppi: ";
		if (!fanMgr_->pcoll->patternVector_[i].PPI_.empty())
		{
			for (int j = 0; j < fanMgr_->pcoll->numPPI_; ++j)
			{
				printValue(fanMgr_->pcoll->patternVector_[i].PPI_[j]);
			}
		}
		std::cout << "\n";
		std::cout << "#      po1: ";
		if (!fanMgr_->pcoll->patternVector_[i].PO1_.empty())
		{
			for (int j = 0; j < fanMgr_->pcoll->numPO_; ++j)
			{
				printValue(fanMgr_->pcoll->patternVector_[i].PO1_[j]);
			}
		}
		std::cout << "\n";
		std::cout << "#      po2: ";
		if (!fanMgr_->pcoll->patternVector_[i].PO2_.empty())
		{
			for (int j = 0; j < fanMgr_->pcoll->numPO_; ++j)
			{
				printValue(fanMgr_->pcoll->patternVector_[i].PO2_[j]);
			}
		}
		std::cout << "\n";
		std::cout << "#      ppo: ";
		if (!fanMgr_->pcoll->patternVector_[i].PPO_.empty())
		{
			for (int j = 0; j < fanMgr_->pcoll->numPPI_; ++j)
			{
				printValue(fanMgr_->pcoll->patternVector_[i].PPO_[j]);
			}
		}
		std::cout << "\n"
							<< "#\n";
	}
	return true;
}

AddFaultCmd::AddFaultCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("add faults");
	optMgr_.setDes("adds faults either by extract from circuit or from file");
	Arg *arg = new Arg(Arg::OPT, "fault type. Can be SA0, SA1, STR, STF", "TYPE");
	optMgr_.regArg(arg);
	arg = new Arg(Arg::OPT, "pin location. Hierarchy separated by '/'", "PIN");
	optMgr_.regArg(arg);
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::STR_REQ, "custom fault file", "FILE");
	opt->addFlag("f");
	opt->addFlag("file");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::BOOL, "add all faults", "");
	opt->addFlag("a");
	opt->addFlag("all");
	optMgr_.regOpt(opt);
}

AddFaultCmd::~AddFaultCmd() {}

bool AddFaultCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR AddFaultCmd::exec(): circuit needed\n";
		return false;
	}

	if (!fanMgr_->fListExtract)
	{
		fanMgr_->fListExtract = new FaultListExtract;
	}

	fanMgr_->fListExtract->extractFaultFromCircuit(fanMgr_->cir);

	// add all faults
	if (optMgr_.isFlagSet("a"))
	{
		addAllFault();
	}
	
	else
	{ // add specific faults
		if (fanMgr_->fListExtract->faultListType_ == FaultListExtract::SAF || fanMgr_->fListExtract->faultListType_ == FaultListExtract::TDF)
		{
			if (optMgr_.getNParsedArg() < 2)
			{
				std::cerr << "**ERROR AddFaultCmd::exec(): need fault type ";
				std::cerr << "and pin location\n";
				return false;
			}
			std::string type = optMgr_.getParsedArg(0);
			if (fanMgr_->fListExtract->faultListType_ == FaultListExtract::SAF &&
					(type != "SA0" && type != "SA1"))
			{
				std::cerr << "**ERROR AddFaultCmd::exec(): stuck-at fault only ";
				std::cerr << "supports SA0 and SA1\n";
				return false;
			}
			if (fanMgr_->fListExtract->faultListType_ == FaultListExtract::TDF &&
					(type != "STR" && type != "STF"))
			{
				std::cerr << "**ERROR AddFaultCmd::exec(): transition delay ";
				std::cerr << "fault only supports STR and STF\n";
				return false;
			}
			std::string pinloc = optMgr_.getParsedArg(1);
			std::string cell = pinloc.substr(0, pinloc.find_first_of('/'));
			std::string pin = pinloc.substr(cell.size());
			if (pin.size() > 0)
			{
				pin = pin.substr(1);
			}
			if (pin.size() == 0)
			{
				if (!addPinFault(type, cell))
				{
					return false;
				}
			}
			else
			{
				if (!addCellFault(type, cell, pin))
				{
					return false;
				}
			}
		}
	}
	fanMgr_->fListExtract_1 = new FaultListExtract(*fanMgr_->fListExtract);

	


	return true;
}

void AddFaultCmd::addAllFault()
{
	std::cout << "#  Building fault list ...\n";
	fanMgr_->tmusg.periodStart();

	fanMgr_->fListExtract->faultsInCircuit_.resize(fanMgr_->fListExtract->extractedFaults_.size());
	FaultPtrListIter it = fanMgr_->fListExtract->faultsInCircuit_.begin();
	for (int i = 0; i < fanMgr_->fListExtract->extractedFaults_.size(); ++i, ++it)
	{
		(*it) = &fanMgr_->fListExtract->extractedFaults_[i];
	}

	TmStat stat;
	fanMgr_->tmusg.getPeriodUsage(stat);
	std::cout << "#  Finished building fault list";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB\n";
}

bool AddFaultCmd::addPinFault(const std::string &type, const std::string &pin)
{
	Port *p = fanMgr_->nl->getTop()->getPort(pin.c_str());
	if (!p)
	{
		std::cerr << "**ERROR AddFaultCmd::exec(): port `";
		std::cerr << pin << "' does not exist\n";
		return false;
	}
	int gid = fanMgr_->cir->portIndexToGateIndex_[p->id_];
	int offset = (type == "SA0" || type == "STR") ? 0 : 1;
	int fid = fanMgr_->fListExtract->gateIndexToFaultIndex_[gid] + offset;
	Fault *f = &fanMgr_->fListExtract->extractedFaults_[fid];
	fanMgr_->fListExtract->faultsInCircuit_.push_back(f);
	return true;
}

bool AddFaultCmd::addCellFault(const std::string &type, const std::string &cell,
															 const std::string &pin)
{
	Cell *c = fanMgr_->nl->getTop()->getCell(cell.c_str());
	if (!c)
	{
		std::cerr << "**ERROR AddFaultCmd::exec(): cell `";
		std::cerr << cell << "' does not exist\n";
		return false;
	}
	Cell *libc = c->libc_;
	Port *p = libc->getPort(pin.c_str());
	if (!p)
	{
		std::cerr << "**ERROR AddFaultCmd::exec(): port `";
		std::cerr << cell << "/" << pin << "' does not exist\n";
		return false;
	}
	PortSet pset = libc->getNetPorts(p->inNet_->id_);
	PortSet::iterator it = pset.begin();
	for (; it != pset.end(); ++it)
	{
		if ((*it)->top_ == libc)
		{
			continue;
		}
		Cell *pmt = (*it)->top_;
		int pmtid = pmt->id_;
		int gid = fanMgr_->cir->cellIndexToGateIndex_[c->id_] + pmtid;
		int pid = 0;
		if ((*it)->type_ == Port::INPUT)
		{
			int nOutput = 0;
			for (int i = 0; i < (*it)->id_; ++i)
			{
				if (pmt->getPort(i)->type_ == Port::OUTPUT)
				{
					++nOutput;
				}
			}
			pid = (*it)->id_ - nOutput + 1;
		}
		int offset = (type == "SA0" || type == "STR") ? 0 : 1;
		int fid = fanMgr_->fListExtract->gateIndexToFaultIndex_[gid] + 2 * pid + offset;
		Fault *f = &fanMgr_->fListExtract->extractedFaults_[fid];
		fanMgr_->fListExtract->faultsInCircuit_.push_back(f);
	}
	return true;
}

ReportFaultCmd::ReportFaultCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("report fault");
	optMgr_.setDes("report fault information");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::STR_REQ, "print only faults with state STATE", "STATE");
	opt->addFlag("s");
	opt->addFlag("state");
	optMgr_.regOpt(opt);
}

ReportFaultCmd::~ReportFaultCmd() {}

bool ReportFaultCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->fListExtract)
	{
		std::cerr << "**ERROR ReportFaultCmd::exec(): fault list needed\n";
		return false;
	}

	bool stateSet = false;
	Fault::FAULT_STATE state = Fault::UD;
	if (optMgr_.isFlagSet("s"))
	{
		stateSet = true;
		std::string stateStr = optMgr_.getFlagVar("s");
		if (stateStr == "ud" || stateStr == "UD")
		{
			state = Fault::UD;
		}
		else if (stateStr == "dt" || stateStr == "DT")
		{
			state = Fault::DT;
		}
		else if (stateStr == "au" || stateStr == "AU")
		{
			state = Fault::AU;
		}
		else if (stateStr == "ti" || stateStr == "TI")
		{
			state = Fault::TI;
		}
		else if (stateStr == "re" || stateStr == "RE")
		{
			state = Fault::RE;
		}
		else if (stateStr == "ab" || stateStr == "AB")
		{
			state = Fault::AB;
		}
		else
		{
			stateSet = true;
			std::cerr << "**WARN ReportFaultCmd::exec(): fault state `";
			std::cerr << stateStr << "' is not supported\n";
		}
	}

	std::cout << "#  fault information\n";
	std::cout << "#    fault type:       ";
	switch (fanMgr_->fListExtract->faultListType_)
	{
		case FaultListExtract::SAF:
			std::cout << "stuck-at fault\n";
			break;
		case FaultListExtract::TDF:
			std::cout << "transition delay fault\n";
			break;
		case FaultListExtract::BRF:
			std::cout << "bridging fault\n";
			break;
		default:
			std::cout << "\n";
			break;
	}
	std::cout << "#    number of faults: " << fanMgr_->fListExtract->faultsInCircuit_.size();
	std::cout << "\n";
	std::cout << "#    type    code    pin (cell)\n";
	std::cout << "#    ----    ----    ----------------------------------\n";
	FaultPtrListIter it = fanMgr_->fListExtract->faultsInCircuit_.begin();
	for (; it != fanMgr_->fListExtract->faultsInCircuit_.end(); ++it)
	{
		if (!stateSet || (*it)->faultState_ != state)
		{
			continue;
		}
		std::cout << "#    ";
		switch ((*it)->faultType_)
		{
			case Fault::SA0:
				std::cout << "SA0     ";
				break;
			case Fault::SA1:
				std::cout << "SA1     ";
				break;
			case Fault::STR:
				std::cout << "STR     ";
				break;
			case Fault::STF:
				std::cout << "STF     ";
				break;
			case Fault::BR:
				std::cout << "BR      ";
				break;
		}
		switch ((*it)->faultState_)
		{
			case Fault::UD:
				std::cout << " UD     ";
				break;
			case Fault::DT:
				std::cout << " DT     ";
				break;
			case Fault::PT:
				std::cout << " PT     ";
				break;
			case Fault::AU:
				std::cout << " AU     ";
				break;
			case Fault::TI:
				std::cout << " TI     ";
				break;
			case Fault::RE:
				std::cout << " RE     ";
				break;
			case Fault::AB:
				std::cout << " AB     ";
				break;
		}
		int cid = fanMgr_->cir->circuitGates_[(*it)->gateID_].cellId_;
		int pid = (*it)->faultyLine_;
		int pmtid = fanMgr_->cir->circuitGates_[(*it)->gateID_].primitiveId_;
		if ((*it)->gateID_ == -1)
		{ // CK
			std::cout << "CK";
		}
		else if ((*it)->gateID_ == -2)
		{ // test_si
			std::cout << "test_si";
		}
		else if ((*it)->gateID_ == -3)
		{ // test_so
			std::cout << "test_so";
		}
		else if ((*it)->gateID_ == -4)
		{ // test_se
			std::cout << "test_se";
		}
		else if (fanMgr_->cir->circuitGates_[(*it)->gateID_].gateType_ == Gate::PI)
		{
			std::cout << fanMgr_->nl->getTop()->getPort(cid)->name_ << " ";
			std::cout << "(primary input)";
		}
		else if (fanMgr_->cir->circuitGates_[(*it)->gateID_].gateType_ == Gate::PO)
		{
			std::cout << fanMgr_->nl->getTop()->getPort(cid)->name_ << " ";
			std::cout << "(primary output)";
		}
		else
		{
			Cell *c = fanMgr_->nl->getTop()->getCell(cid);
			// std::cout << "test" << c->name_<< " " << cid << "\n";
			Cell *libc = c->libc_;
			Cell *pmt = libc->getCell(pmtid);
			Port *p = NULL;
			if (pid < 0)
			{ // must be CK,SE,SI pins on FF
				if (pid == -1)
				{
					std::cout << c->name_ << "/CK ";
				}
				else if (pid == -2)
				{
					std::cout << c->name_ << "/SE ";
				}
				else if (pid == -3)
				{
					std::cout << c->name_ << "/SI ";
				}
				else
				{
					std::cout << c->name_ << "/QN ";
				}
			}
			else if (pid == 0)
			{ // output
				if (!strcmp(libc->name_, "SDFFXL"))
				{
					std::cout << c->name_ << "/Q ";
				}
				else
				{
					for (int i = 0; i < pmt->getNPort(); ++i)
					{
						if (pmt->getPort(i)->type_ != Port::OUTPUT)
						{
							continue;
						}
						Net *n = pmt->getPort(i)->exNet_;
						if (!n)
						{
							continue;
						}
						PortSet pset = libc->getNetPorts(n->id_);
						PortSet::iterator pit = pset.begin();
						for (; pit != pset.end(); ++pit)
						{
							if ((*pit)->top_ != libc)
							{
								continue;
							}
							p = (*pit);
							break;
						}
						if (p)
						{
							break;
						}
					}
				}
			}
			else
			{ // input
				int inCount = 0;
				for (int i = 0; i < pmt->getNPort(); ++i)
				{
					if (pmt->getPort(i)->type_ == Port::INPUT)
					{
						++inCount;
					}
					if (inCount != pid)
					{
						continue;
					}
					Net *n = pmt->getPort(i)->exNet_;
					if (!n)
					{
						continue;
					}
					PortSet pset = libc->getNetPorts(n->id_);
					PortSet::iterator pit = pset.begin();
					for (; pit != pset.end(); ++pit)
					{
						if ((*pit)->top_ != libc)
						{
							continue;
						}
						p = (*pit);
						break;
					}
					if (p)
					{
						break;
					}
				}
			}
			if (p)
			{
				std::cout << c->name_ << "/" << p->name_ << " ";
			}
			std::cout << "(" << libc->name_ << ")";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

	return true;
}

ReportCircuitCmd::ReportCircuitCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("report circuit");
	optMgr_.setDes("report circuit information");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}
ReportCircuitCmd::~ReportCircuitCmd() {}

bool ReportCircuitCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR ReportCircuitCmd::exec(): circuit needed\n";
		return false;
	}

	Cell *top = fanMgr_->cir->pNetlist_->getTop();
	std::cout << "#  circuit information\n";
	std::cout << "#    netlist:         " << top->name_ << "\n";
	std::cout << "#    number of PIs:   " << fanMgr_->cir->numPI_ << "\n";
	std::cout << "#    number of PPIs:  " << fanMgr_->cir->numPPI_ << "\n";
	std::cout << "#    number of POs:   " << fanMgr_->cir->numPO_ << "\n";
	std::cout << "#    number of combs: " << fanMgr_->cir->numComb_ << "\n";
	std::cout << "#    number of gates: " << fanMgr_->cir->numGate_ << "\n";
	std::cout << "#    number of nets:  " << fanMgr_->cir->numNet_ << "\n";

	return true;
}

ReportGateCmd::ReportGateCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("report gate information");
	optMgr_.setDes("reports GATE information in the circuit");
	Arg *arg = new Arg(Arg::OPT_INF, "if no name is specified, all gates will be reported", "GATE");
	optMgr_.regArg(arg);
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}
ReportGateCmd::~ReportGateCmd() {}

bool ReportGateCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR ReportGateCmd::exec(): circuit needed\n";
		return false;
	}

	if (optMgr_.getNParsedArg() == 0)
	{
		for (int i = 0; i < fanMgr_->cir->numGate_ * fanMgr_->cir->numFrame_; ++i)
		{
			reportGate(i);
		}
	}
	else
	{
		for (int i = 0; i < optMgr_.getNParsedArg(); ++i)
		{
			std::string name = optMgr_.getParsedArg(i);
			Cell *c = fanMgr_->nl->getTop()->getCell(name.c_str());
			if (c)
			{
				for (int j = 0; j < c->libc_->getNCell(); ++j)
				{
					reportGate(fanMgr_->cir->cellIndexToGateIndex_[c->id_] + j);
				}
			}
			Port *p = fanMgr_->nl->getTop()->getPort(name.c_str());
			if (p)
			{
				reportGate(fanMgr_->cir->portIndexToGateIndex_[p->id_]);
			}
			if (!c && !p)
			{
				std::cerr << "**ERROR ReportGateCmd::exec(): cell or port `";
				std::cerr << name << "' does not exist\n";
			}
		}
	}
	return true;
}

void ReportGateCmd::reportGate(const int &i) const
{
	Gate *g = &fanMgr_->cir->circuitGates_[i];
	std::cout << "#  ";
	if (g->gateType_ == Gate::PI || g->gateType_ == Gate::PO)
	{
		std::cout << fanMgr_->nl->getTop()->getPort((size_t)g->cellId_)->name_;
	}
	else
	{
		std::cout << fanMgr_->nl->getTop()->getCell((size_t)g->cellId_)->name_;
	}
	std::cout << " id(" << i << ") ";
	std::cout << "lvl(" << g->numLevel_ << ") ";
	std::cout << "type(" << g->gateType_ << ") ";
	std::cout << "frame(" << g->frame_ << ")";
	std::cout << "\n";
	std::cout << "#    fi[" << g->numFI_ << "]";
	for (int j = 0; j < g->numFI_; ++j)
	{
		std::cout << " " << g->faninVector_[j];
	}
	std::cout << "\n";
	std::cout << "#    fo[" << g->numFO_ << "]";
	for (int j = 0; j < g->numFO_; ++j)
	{
		std::cout << " " << g->fanoutVector_[j];
	}
	std::cout << "\n\n";
}

ReportValueCmd::ReportValueCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("report gate values");
	optMgr_.setDes("reports GATE values in the circuit");
	Arg *arg = new Arg(Arg::OPT_INF, "if no name is specified, all gates will be reported", "GATE");
	optMgr_.regArg(arg);
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}
ReportValueCmd::~ReportValueCmd() {}

bool ReportValueCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR ReportValueCmd::exec(): circuit needed\n";
		return false;
	}

	if (optMgr_.getNParsedArg() == 0)
	{
		for (int i = 0; i < fanMgr_->cir->totalGate_; ++i)
		{
			reportValue(i);
		}
	}
	else
	{
		for (int i = 0; i < optMgr_.getNParsedArg(); ++i)
		{
			std::string name = optMgr_.getParsedArg(i);
			Cell *c = fanMgr_->nl->getTop()->getCell(name.c_str());
			if (c)
			{
				for (int j = 0; j < c->libc_->getNCell(); ++j)
				{
					reportValue(fanMgr_->cir->cellIndexToGateIndex_[c->id_] + j);
				}
			}
			Port *p = fanMgr_->nl->getTop()->getPort(name.c_str());
			if (p)
			{
				reportValue(fanMgr_->cir->portIndexToGateIndex_[p->id_]);
			}
			if (!c && !p)
			{
				std::cerr << "**ERROR ReportValueCmd::exec(): cell or port `";
				std::cerr << name << "' does not exist\n";
			}
		}
	}
	return true;
}


void printFaultsToFile(const FaultPtrList& faults, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing.\n";
        return;
    }

    for (const auto& fault : faults) {
        file << "Fault ID: " << fault->gateID_
             << ", Type: " << fault->faultType_
             << ", Line: " << fault->faultyLine_
             << ", State: " << fault->faultState_
             << ", Equivalent: " << fault->equivalent_ << "\n";
    }

    file.close();
}




void ReportValueCmd::reportValue(const int &i) const
{
	Gate *g = &fanMgr_->cir->circuitGates_[i];
	std::cout << "#  ";
	if (g->gateType_ == Gate::PI || g->gateType_ == Gate::PO)
	{
		std::cout << fanMgr_->nl->getTop()->getPort((size_t)g->cellId_)->name_;
	}
	else
	{
		std::cout << fanMgr_->nl->getTop()->getCell((size_t)g->cellId_)->name_;
	}
	std::cout << " id(" << i << ") ";
	std::cout << "lvl(" << g->numLevel_ << ") ";
	std::cout << "type(" << g->gateType_ << ") ";
	std::cout << "frame(" << g->frame_ << ")";
	std::cout << "\n";
	std::cout << "#    good:   ";
	printSimulationValue(g->goodSimLow_, g->goodSimHigh_);
	std::cout << "\n";
	std::cout << "#    faulty: ";
	printSimulationValue(g->faultSimLow_, g->faultSimHigh_);
	std::cout << "\n\n";
}

ReportStatsCmd::ReportStatsCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("report statistics");
	optMgr_.setDes("reports statistics on fault coverage");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}
ReportStatsCmd::~ReportStatsCmd() {}

bool ReportStatsCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->fListExtract || fanMgr_->fListExtract->faultsInCircuit_.size() == 0)
	{
		std::cerr << "**WARN ReportStatsCmd::exec(): no statistics\n";
		return false;
	}

	// determine fault model
	std::string ftype = "";
	switch (fanMgr_->fListExtract->faultListType_)
	{
		case FaultListExtract::SAF:
			ftype = "SAF";
			break;
		case FaultListExtract::TDF:
			ftype = "TDF";
			break;
		case FaultListExtract::BRF:
			ftype = "BRF";
			break;
	}

	// determine pattern type
	std::string ptype = "";
	switch (fanMgr_->pcoll->type_)
	{
		case PatternProcessor::BASIC_SCAN:
			ptype = "BASIC";
			break;
		case PatternProcessor::LAUNCH_CAPTURE:
			ptype = "LOC";
			break;
		case PatternProcessor::LAUNCH_SHIFT:
			ptype = "LOS";
			break;
	}

	// determine atpg runtime
	// float rtime = (double)fanMgr_->atpgStat.rTime / 1000000.0;

	size_t npat = 0;

	if (fanMgr_->pcoll)
	{
		npat = fanMgr_->pcoll->patternVector_.size();
	}

	size_t numCollapsedFaults = 0;
	size_t fu = 0;
	size_t ud = 0;
	size_t dt = 0;
	size_t pt = 0;
	size_t au = 0;
	size_t ti = 0;
	size_t re = 0;
	size_t ab = 0;

	FaultPtrListIter it = fanMgr_->fListExtract->faultsInCircuit_.begin();

	// FaultPtrListIter it_ = fanMgr_->fListExtract_1->faultsInCircuit_.begin();

	// printFaultsToFile(fanMgr_->fListExtract->faultsInCircuit_, "faultsList1.txt");

	// printFaultsToFile(fanMgr_->fListExtract_1->faultsInCircuit_, "faultsList2.txt");

	// while (it != fanMgr_->fListExtract->faultsInCircuit_.end() &&
    //    it_ != fanMgr_->fListExtract_1->faultsInCircuit_.end()) {
    // // 检查两个列表中相同位置的故障状态
    // if ((*it)->faultState_ == Fault::DT || (*it_)->faultState_ == Fault::DT) {
    //     // 如果任一故障的状态为DT，将第一个列表中的故障状态更新为DT
    //     (*it)->faultState_ = Fault::DT;
    // }
    // // 移动到下一个故障
    // ++it;
    // ++it_;
	// }



	for (; it != fanMgr_->fListExtract->faultsInCircuit_.end(); ++it)
	{
		++numCollapsedFaults;
		int eq = (*it)->equivalent_;
		fu += eq;
		switch ((*it)->faultState_)
		{
			case Fault::UD:
				ud += eq;
				break;
			case Fault::DT:
				dt += eq;
				break;
			case Fault::PT:
				pt += eq;
				break;
			case Fault::AU:
				au += eq;
				break;
			case Fault::TI:
				ti += eq;
				break;
			case Fault::RE:
				re += eq;
				break;
			case Fault::AB:
				ab += eq;
				break;
		}
	}

	float fc = (float)dt / (float)fu * 100;
	float tc = (float)dt / (float)(ud + dt + pt + ab) * 100;
	float ae = (float)(dt + au + ti + re) / (float)fu * 100;

	std::cout << std::right;
	std::cout << std::setprecision(4);
	std::cout << "#                 Statistics Report\n";
	std::cout << "#  Circuit name                  " << std::setw(19);
	std::cout << fanMgr_->nl->getTop()->name_ << "\n";
	std::cout << "#  Fault model                   " << std::setw(19) << ftype << "\n";
	std::cout << "#  Pattern type                  " << std::setw(19) << ptype << "\n";
	std::cout << "#  -------------------------------------------------\n";
	std::cout << "#  Fault classes                             #faults\n";
	std::cout << "#  ----------------------------  -------------------\n";
	std::cout << "#    FU (full)                   " << std::setw(19) << fu << "\n";
	std::cout << "#    FU (collapsed)              " << std::setw(19) << numCollapsedFaults << "\n";
	std::cout << "#    --------------------------  -------------------\n";
	std::cout << "#    UD (undetected)             " << std::setw(19) << ud << "\n";
	std::cout << "#    PT (possibly testable)      " << std::setw(19) << pt << "\n";
	std::cout << "#    AU (atpg untestable)        " << std::setw(19) << au << "\n";
	std::cout << "#    RE (redundant)              " << std::setw(19) << re << "\n";
	std::cout << "#    AB (atpg abort)             " << std::setw(19) << ab << "\n";
	std::cout << "#    TI (tied)                   " << std::setw(19) << ti << "\n";
	std::cout << "#    --------------------------  -------------------\n";
	std::cout << "#    DT (detected)               " << std::setw(19) << dt << "\n";
	std::cout << "#  -------------------------------------------------\n";
	std::cout << "#  Coverage                               percentage\n";
	std::cout << "#    --------------------------  -------------------\n";
	std::cout << "#    test coverage                            ";
	std::cout << std::setw(5) << tc << "%\n";
	std::cout << "#    fault coverage                           ";
	std::cout << std::setw(5) << fc << "%\n";
	std::cout << "#    atpg effectiveness                       ";
	std::cout << std::setw(5) << ae << "%\n";
	std::cout << "#  -------------------------------------------------\n";
	std::cout << "#  #Patterns                     " << std::setw(19) << npat << "\n";
	std::cout << "#  -------------------------------------------------\n";
	std::cout << "#  ATPG runtime                  " << std::setw(17) << rtime;
	std::cout << " s\n";
	std::cout << "#  -------------------------------------------------\n";

	return true;
}

AddPinConsCmd::AddPinConsCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("add pin constraint");
	optMgr_.setDes("constraint PI(s) to 0 or 1");
	Arg *arg = new Arg(Arg::REQ_INF, "PIs to be constrained", "PI");
	optMgr_.regArg(arg);
	arg = new Arg(Arg::REQ, "constraint value, 0 or 1", "<0|1>");
	optMgr_.regArg(arg);
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}

AddPinConsCmd::~AddPinConsCmd() {}

bool AddPinConsCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR AddPinConsCmd::exec(): circuit needed";
		std::cerr << "\n";
		return false;
	}

	if (optMgr_.getNParsedArg() < 2)
	{
		std::cerr << "**ERROR AddPinConsCmd::exec(): need at least one PI ";
		std::cerr << "and the constraint value\n";
		return false;
	}

	size_t npi = optMgr_.getNParsedArg() - 1;
	int cons = atoi(optMgr_.getParsedArg(npi).c_str());
	for (int i = 0; i < npi; ++i)
	{
		std::string pinName = optMgr_.getParsedArg(i);
		Port *p = fanMgr_->nl->getTop()->getPort(pinName.c_str());
		if (!p)
		{
			std::cerr << "**ERROR AddPinConsCmd::exec(): Port `" << pinName;
			std::cerr << "' not found\n";
			continue;
		}
		int gid = fanMgr_->cir->portIndexToGateIndex_[p->id_];
		if (fanMgr_->cir->circuitGates_[gid].gateType_ != Gate::PI)
		{
			std::cerr << "**ERROR AddPinConsCmd::exec(): Port `" << pinName;
			std::cerr << "' is not PI\n";
			continue;
		}
		fanMgr_->cir->circuitGates_[gid].hasConstraint_ = true;
		if (cons)
		{
			fanMgr_->cir->circuitGates_[gid].constraint_ = PARA_H;
		}
		else
		{
			fanMgr_->cir->circuitGates_[gid].constraint_ = PARA_L;
		}
	}
	return true;
}

RunLogicSimCmd::RunLogicSimCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("run logic simulation");
	optMgr_.setDes("run logic simulation on the given pattern");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}

RunLogicSimCmd::~RunLogicSimCmd() {}

bool RunLogicSimCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR RunLogicSimCmd::exec(): circuit needed\n";
		return false;
	}

	if (!fanMgr_->pcoll)
	{
		std::cerr << "**ERROR RunLogicSimCmd::exec(): pattern needed\n";
		return false;
	}

	fanMgr_->tmusg.periodStart();
	std::cout << "#  Performing logic simulation ...\n";

	Simulator sim(fanMgr_->cir);
	sim.parallelPatternGoodSimWithAllPattern(fanMgr_->pcoll);

	TmStat stat;
	fanMgr_->tmusg.getPeriodUsage(stat);
	std::cout << "#  Finished logic simulation";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB\n";

	return true;
}

RunFaultSimCmd::RunFaultSimCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("run fault simulation");
	optMgr_.setDes("run fault simulation on the given pattern");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::STR_REQ, "simulation METHOD. Choose either pp (parallel pattern) or pf (parallel fault)", "METHOD");
	opt->addFlag("m");
	opt->addFlag("method");
	optMgr_.regOpt(opt);
}
RunFaultSimCmd::~RunFaultSimCmd() {}


void printPatternProcessorToFile(const PatternProcessor& processor, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing.\n";
        return;
    }

    file << "numPI: " << processor.numPI_ << "\n";
    file << "numPPI: " << processor.numPPI_ << "\n";
    file << "numSI: " << processor.numSI_ << "\n";
    file << "numPO: " << processor.numPO_ << "\n";
    
    file << "pPIorder: ";
    for (const auto& pi : processor.pPIorder_) {
        file << pi << " ";
    }
    file << "\n";
    
    file << "pPPIorder: ";
    for (const auto& ppi : processor.pPPIorder_) {
        file << ppi << " ";
    }
    file << "\n";
    
    file << "pPOorder: ";
    for (const auto& po : processor.pPOorder_) {
        file << po << " ";
    }
    file << "\n";

    file.close();
}

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
// 假设这里已经包含了Circuit和Gate的定义

void printCircuitToFile(const Circuit& circuit, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filename << " for writing.\n";
        return;
    }

    // 打印Circuit的基本信息
    file << "Netlist: " << (circuit.pNetlist_ ? "Exists" : "Not exists") << "\n";
    file << "Number of PIs: " << circuit.numPI_ << "\n";
    file << "Number of PPIs: " << circuit.numPPI_ << "\n";
    file << "Number of POs: " << circuit.numPO_ << "\n";
    file << "Number of Combinational Gates: " << circuit.numComb_ << "\n";
    file << "Number of Gates: " << circuit.numGate_ << "\n";
    file << "Number of Nets: " << circuit.numNet_ << "\n";
    file << "Circuit Level: " << circuit.circuitLvl_ << "\n";
    file << "Number of Time Frames: " << circuit.numFrame_ << "\n";
    file << "Time Frame Connection Type: " << (circuit.timeFrameConnectType_ == Circuit::CAPTURE ? "CAPTURE" : "SHIFT") << "\n";
    file << "Total Gates: " << circuit.totalGate_ << "\n";
    file << "Total Levels: " << circuit.totalLvl_ << "\n";

    // 打印每个Gate的详细信息
    file << "\nCircuit Gates Details:\n";
    for (const auto& gate : circuit.circuitGates_) {
        file << "Gate ID: " << gate.gateId_
             << ", Cell ID: " << gate.cellId_
             << ", Primitive ID: " << gate.primitiveId_
             << ", Level: " << gate.numLevel_
             << ", Frame: " << gate.frame_
             << ", Type: " << gate.gateType_
             << ", NumFI: " << gate.numFI_
             << ", NumFO: " << gate.numFO_ << "\n";

        file << "  Fanin IDs: ";
        for (const auto& fi : gate.faninVector_) {
            file << fi << " ";
        }
        file << "\n";

        file << "  Fanout IDs: ";
        for (const auto& fo : gate.fanoutVector_) {
            file << fo << " ";
        }
        file << "\n\n";
    }

    file.close();
}



#include <functional>
#include <future>
#include <thread>

class SimpleThreadPool {
public:
    template<typename Func>
    auto submit(Func func) -> std::future<decltype(func())> {
        // 使用std::function封装Func，以便处理任意类型的可调用对象
        auto task = std::make_shared<std::packaged_task<decltype(func())()>>(std::function<decltype(func())()>(func));
        
        auto res = task->get_future();
        std::thread([task]() { (*task)(); }).detach();
        return res;
    }
};






bool RunFaultSimCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR RunFaultSimCmd::exec(): circuit needed\n";
		return false;
	}

	if (!fanMgr_->pcoll)
	{
		std::cerr << "**ERROR RunFaultSimCmd::exec(): pattern needed\n";
		return false;
	}

	if (!fanMgr_->fListExtract || fanMgr_->fListExtract->faultsInCircuit_.size() == 0)
	{
		std::cerr << "**ERROR RunFaultSimCmd::exec(): fault list needed\n";
		return false;
	}

	if (!fanMgr_->sim)
	{
		fanMgr_->sim_1 = new Simulator(fanMgr_->cir_1);
		fanMgr_->sim = new Simulator(fanMgr_->cir);
		fanMgr_->sim_3 = new Simulator(fanMgr_->cir_3);
		fanMgr_->sim_2 = new Simulator(fanMgr_->cir_2);
		fanMgr_->sim_4 = new Simulator(fanMgr_->cir_4);
		fanMgr_->sim_5 = new Simulator(fanMgr_->cir_5);
		fanMgr_->sim_6 = new Simulator(fanMgr_->cir_6);
		fanMgr_->sim_7 = new Simulator(fanMgr_->cir_7);
		fanMgr_->sim_8 = new Simulator(fanMgr_->cir_8);
		fanMgr_->sim_9 = new Simulator(fanMgr_->cir_9);
		fanMgr_->sim_10 = new Simulator(fanMgr_->cir_10);
		fanMgr_->sim_11 = new Simulator(fanMgr_->cir_11);
		fanMgr_->sim_12 = new Simulator(fanMgr_->cir_12);
		fanMgr_->sim_13 = new Simulator(fanMgr_->cir_13);
		fanMgr_->sim_14 = new Simulator(fanMgr_->cir_14);
		fanMgr_->sim_15 = new Simulator(fanMgr_->cir_15);
		fanMgr_->sim_16 = new Simulator(fanMgr_->cir_16);
		fanMgr_->sim_17 = new Simulator(fanMgr_->cir_17);
		fanMgr_->sim_18 = new Simulator(fanMgr_->cir_18);
		fanMgr_->sim_19 = new Simulator(fanMgr_->cir_19);
		fanMgr_->sim_20 = new Simulator(fanMgr_->cir_20);
		fanMgr_->sim_21 = new Simulator(fanMgr_->cir_21);
		fanMgr_->sim_22 = new Simulator(fanMgr_->cir_22);
		fanMgr_->sim_23 = new Simulator(fanMgr_->cir_23);
		fanMgr_->sim_24 = new Simulator(fanMgr_->cir_24);
		fanMgr_->sim_25 = new Simulator(fanMgr_->cir_25);
		fanMgr_->sim_26 = new Simulator(fanMgr_->cir_26);
		fanMgr_->sim_27 = new Simulator(fanMgr_->cir_27);
		fanMgr_->sim_28 = new Simulator(fanMgr_->cir_28);
		fanMgr_->sim_29 = new Simulator(fanMgr_->cir_29);
		fanMgr_->sim_30 = new Simulator(fanMgr_->cir_30);
		fanMgr_->sim_31 = new Simulator(fanMgr_->cir_31);
		

	}

	std::cout << "#  Performing fault simulation ...\n";
	fanMgr_->tmusg.periodStart();

	// printFaultsToFile(fanMgr_->fListExtract->faultsInCircuit_, "faultsList3.txt");

	// printFaultsToFile(fanMgr_->fListExtract_1->faultsInCircuit_, "faultsList4.txt");
	
	// printPatternProcessorToFile(*(fanMgr_->pcoll), "PatternProcessorOutput1.txt");

	// // printPatternProcessorToFile(*(fanMgr_->pcoll_1), "PatternProcessorOutput2.txt");

	// printCircuitToFile(*(fanMgr_->cir), "CircuitDetails1.txt");

	// printCircuitToFile(*(fanMgr_->cir_1), "CircuitDetails2.txt");

	

	SimpleThreadPool pool;

    // 使用lambda表达式提交任务
    if (optMgr_.isFlagSet("m") && optMgr_.getFlagVar("m") == "pf") {
        auto fut1 = pool.submit([this]{
            fanMgr_->sim->parallelPatternFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract);
        });
        fut1.get(); // 等待任务完成
    } else {
        auto fut1 = pool.submit([this]{
            fanMgr_->sim->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 0);
        });
        auto fut2 = pool.submit([this]{
            fanMgr_->sim_1->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 1);
        });
		auto fut3 = pool.submit([this]{
            fanMgr_->sim_2->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 2);
        });
		auto fut4 = pool.submit([this]{
            fanMgr_->sim_3->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 3);
        });
        
		auto fut5 = pool.submit([this]{
    		fanMgr_->sim_4->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 4);
		});
		auto fut6 = pool.submit([this]{
			fanMgr_->sim_5->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 5);
		});
		auto fut7 = pool.submit([this]{
			fanMgr_->sim_6->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 6);
		});
		auto fut8 = pool.submit([this]{
			fanMgr_->sim_7->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 7);
		});
		auto fut9 = pool.submit([this]{
			fanMgr_->sim_8->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 8);
		});
		auto fut10 = pool.submit([this]{
			fanMgr_->sim_9->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 9);
		});
		auto fut11 = pool.submit([this]{
			fanMgr_->sim_10->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 10);
		});
		auto fut12 = pool.submit([this]{
			fanMgr_->sim_11->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 11);
		});
		auto fut13 = pool.submit([this]{
			fanMgr_->sim_12->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 12);
		});
		auto fut14 = pool.submit([this]{
			fanMgr_->sim_13->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 13);
		});
		auto fut15 = pool.submit([this]{
			fanMgr_->sim_14->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 14);
		});
		auto fut16 = pool.submit([this]{
			fanMgr_->sim_15->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 15);
		});
		auto fut17 = pool.submit([this]{
			fanMgr_->sim_16->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 16);
		});
		auto fut18 = pool.submit([this]{
			fanMgr_->sim_17->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 17);
		});
		auto fut19 = pool.submit([this]{
			fanMgr_->sim_18->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 18);
		});
		auto fut20 = pool.submit([this]{
			fanMgr_->sim_19->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 19);
		});
		auto fut21 = pool.submit([this]{
			fanMgr_->sim_20->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 20);
		});
		auto fut22 = pool.submit([this]{
			fanMgr_->sim_21->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 21);
		});
		auto fut23 = pool.submit([this]{
			fanMgr_->sim_22->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 22);
		});
		auto fut24 = pool.submit([this]{
			fanMgr_->sim_23->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 23);
		});
		auto fut25 = pool.submit([this]{
			fanMgr_->sim_24->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 24);
		});
		auto fut26 = pool.submit([this]{
			fanMgr_->sim_25->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 25);
		});
		auto fut27 = pool.submit([this]{
			fanMgr_->sim_26->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 26);
		});
		auto fut28 = pool.submit([this]{
			fanMgr_->sim_27->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 27);
		});
		auto fut29 = pool.submit([this]{
			fanMgr_->sim_28->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 28);
		});
		auto fut30 = pool.submit([this]{
			fanMgr_->sim_29->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 29);
		});
		auto fut31 = pool.submit([this]{
			fanMgr_->sim_30->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 30);
		});
		auto fut32 = pool.submit([this]{
			fanMgr_->sim_31->parallelFaultFaultSimWithAllPattern(fanMgr_->pcoll, fanMgr_->fListExtract, 31);
		});
		

		fut1.get(); // 等待第一个任务完成
		fut2.get(); // 等待第二个任务完成
		fut3.get(); // 等待第三个任务完成
		fut4.get(); // 等待第四个任务完成
		fut5.get(); // 等待第五个任务完成
		fut6.get(); // 等待第六个任务完成
		fut7.get(); // 等待第七个任务完成
		fut8.get(); // 等待第八个任务完成
		fut9.get(); // 等待第九个任务完成
		fut10.get(); // 等待第十个任务完成
		fut11.get(); // 等待第十一个任务完成
		fut12.get(); // 等待第十二个任务完成
		fut13.get(); // 等待第十三个任务完成
		fut14.get(); // 等待第十四个任务完成
		fut15.get(); // 等待第十五个任务完成
		fut16.get(); // 等待第十六个任务完成
		fut17.get(); // 等待第十七个任务完成
		fut18.get(); // 等待第十八个任务完成
		fut19.get(); // 等待第十九个任务完成
		fut20.get(); // 等待第二十个任务完成
		fut21.get(); // 等待第二十一个任务完成
		fut22.get(); // 等待第二十二个任务完成
		fut23.get(); // 等待第二十三个任务完成
		fut24.get(); // 等待第二十四个任务完成
		fut25.get(); // 等待第二十五个任务完成
		fut26.get(); // 等待第二十六个任务完成
		fut27.get(); // 等待第二十七个任务完成
		fut28.get(); // 等待第二十八个任务完成
		fut29.get(); // 等待第二十九个任务完成
		fut30.get(); // 等待第三十个任务完成
		fut31.get(); // 等待第三十一个任务完成
		fut32.get(); // 等待第三十二个任务完成
		


    }

    // ...之后的代码省略...
    return true;

	TmStat stat;
	fanMgr_->tmusg.getPeriodUsage(stat);
	std::cout << "#  Finished fault simulation";
	std::cout << "    " << (double)stat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)stat.vmSize / 1024.0 << " MB\n";
	rtime = (double)stat.rTime / 1000000.0;

	return true;
}

RunAtpgCmd::RunAtpgCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("run automatic test pattern generation");
	optMgr_.setDes("run automatic test pattern generation");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}

RunAtpgCmd::~RunAtpgCmd() {}

bool RunAtpgCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR RunFaultSimCmd::exec(): circuit needed\n";
		return false;
	}

	if (!fanMgr_->pcoll)
	{
		fanMgr_->pcoll = new PatternProcessor;
	}

	if (!fanMgr_->fListExtract)
	{
		fanMgr_->fListExtract = new FaultListExtract;
		fanMgr_->fListExtract->extractFaultFromCircuit(fanMgr_->cir);
	}

	if (!fanMgr_->sim)
	{
		fanMgr_->sim = new Simulator(fanMgr_->cir);
	}

	delete fanMgr_->atpg;
	fanMgr_->atpg = new Atpg(fanMgr_->cir, fanMgr_->sim);

	std::cout << "#  Performing pattern generation ...\n";
	fanMgr_->tmusg.periodStart();

	fanMgr_->atpg->generatePatternSet(fanMgr_->pcoll, fanMgr_->fListExtract, true);

	fanMgr_->tmusg.getPeriodUsage(fanMgr_->atpgStat);
	std::cout << "#  Finished pattern generation";
	std::cout << "    " << (double)fanMgr_->atpgStat.rTime / 1000000.0 << " s";
	std::cout << "    " << (double)fanMgr_->atpgStat.vmSize / 1024.0 << " MB";
	std::cout << "\n";
	rtime = (double)fanMgr_->atpgStat.rTime / 1000000.0;

	return true;
}

WritePatCmd::WritePatCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("write patterns");
	optMgr_.setDes("writes patterns to FILE");
	Arg *arg = new Arg(Arg::REQ, "output pattern file", "FILE");
	optMgr_.regArg(arg);
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::STR_REQ, "pattern format. Currently supports `pat' and `ascii'", "FORMAT");
	opt->addFlag("f");
	opt->addFlag("format");
	optMgr_.regOpt(opt);
}

WritePatCmd::~WritePatCmd() {}

bool WritePatCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR WritePatternCmd::exec(): output file needed";
		std::cerr << "\n";
		return false;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR WritePatternCmd::exec(): circuit needed\n";
		return false;
	}

	if (!fanMgr_->pcoll)
	{
		std::cerr << "**ERROR WritePatternCmd::exec(): pattern needed\n";
		return false;
	}

	std::cout << "#  Writing pattern to `" << optMgr_.getParsedArg(0) << "' ...";
	std::cout << "\n";
	PatternWriter writer(fanMgr_->pcoll, fanMgr_->cir);
	if (optMgr_.getFlagVar("f") == "lht")
	{
		if (!writer.writeLht(optMgr_.getParsedArg(0).c_str()))
		{
			std::cerr << "**ERROR WritePatternCmd::exec(): writer failed\n";
			return false;
		}
	}
	else if (optMgr_.getFlagVar("f") == "ascii")
	{
		if (!writer.writeAscii(optMgr_.getParsedArg(0).c_str()))
		{
			std::cerr << "**ERROR WritePatternCmd::exec(): writer failed\n";
			return false;
		}
	}
	else if (optMgr_.getFlagVar("f") == "pat" || optMgr_.getFlagVar("f") == "")
	{
		if (!writer.writePattern(optMgr_.getParsedArg(0).c_str()))
		{
			std::cerr << "**ERROR WritePatternCmd::exec(): writer failed\n";
			return false;
		}
	}
	else
	{
		std::cerr << "**ERROR WritePatternCmd::exec(): undefined parameter in -f\n";
	}

	return true;
}

// Ne
AddScanChainsCmd::AddScanChainsCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("Add Scan Chains");
	optMgr_.setDes("Add Scan Chains to FFs");
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}

AddScanChainsCmd::~AddScanChainsCmd() {}

bool AddScanChainsCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR AddScanChainsCmd::exec(): circuit needed\n";
		return false;
	}

	std::cout << "#  Add Scan Chains \n";

	return true;
}
// Ne

WriteProcCmd::WriteProcCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("write test procedure file");
	optMgr_.setDes("create test procedure file ");
	Arg *arg = new Arg(Arg::REQ, "output test procedure file", "FILE");
	optMgr_.regArg(arg);
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
}

WriteProcCmd::~WriteProcCmd() {}

bool WriteProcCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR WritePatternCmd::exec(): output file needed";
		std::cerr << "\n";
		return false;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR WritePatternCmd::exec(): circuit needed\n";
		return false;
	}

	std::cout << "#  Writing test procedure file ...\n";
	ProcedureWriter writer(fanMgr_->cir);
	if (!writer.writeProcedure(optMgr_.getParsedArg(0).c_str()))
	{
		std::cerr << "**ERROR WritePatternCmd::exec(): writer failed\n";
		return false;
	}

	return true;
}

WriteStilCmd::WriteStilCmd(const std::string &name, FanMgr *fanMgr) : Cmd(name)
{
	fanMgr_ = fanMgr;
	optMgr_.setName(name);
	optMgr_.setShortDes("write to STIL");
	optMgr_.setDes("writes to STIL");
	Arg *arg = new Arg(Arg::REQ, "output pattern file", "FILE");
	optMgr_.regArg(arg);
	Opt *opt = new Opt(Opt::BOOL, "print usage", "");
	opt->addFlag("h");
	opt->addFlag("help");
	optMgr_.regOpt(opt);
	opt = new Opt(Opt::STR_REQ, "pattern format. Currently supports `pat'", "FORMAT");
	opt->addFlag("f");
	opt->addFlag("format");
	optMgr_.regOpt(opt);
}

WriteStilCmd::~WriteStilCmd() {}

bool WriteStilCmd::exec(const std::vector<std::string> &argv)
{
	optMgr_.parse(argv);

	if (optMgr_.isFlagSet("h"))
	{
		optMgr_.usage();
		return true;
	}

	if (optMgr_.getNParsedArg() < 1)
	{
		std::cerr << "**ERROR WriteSTILCmd::exec(): output file needed";
		std::cerr << "\n";
		return false;
	}

	if (!fanMgr_->cir)
	{
		std::cerr << "**ERROR WriteSTILCmd::exec(): circuit needed\n";
		return false;
	}

	if (!fanMgr_->pcoll)
	{
		std::cerr << "**ERROR WriteSTILCmd::exec(): pattern needed\n";
		return false;
	}

	std::cout << "#  Writing pattern to STIL...\n";
	PatternWriter writer(fanMgr_->pcoll, fanMgr_->cir);

	if (!writer.writeSTIL(optMgr_.getParsedArg(0).c_str()))
	{
		std::cerr << "**ERROR WriteSTILCmd::exec(): writer failed\n";
		return false;
	}

	return true;
}
