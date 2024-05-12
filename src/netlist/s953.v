/*
###############################################################
#  Generated by:      Cadence Encounter 10.13-s292_1
#  OS:                Linux x86_64(Host ID cad29)
#  Generated on:      Tue May  6 02:14:40 2014
#  Design:            s953
#  Command:           saveNetlist netlist_PR/s953/s953_placed.v
###############################################################
*/
module s953 (
	CK, 
	Rdy1RtHS1, 
	Rdy2RtHS1, 
	Rdy1BmHS1, 
	Rdy2BmHS1, 
	InDoneHS1, 
	RtTSHS1, 
	TpArrayHS1, 
	OutputHS1, 
	WantBmHS1, 
	WantRtHS1, 
	OutAvHS1, 
	FullOHS1, 
	FullIHS1, 
	Prog_2, 
	Prog_1, 
	Prog_0, 
	test_se, 
	test_si, 
	ReWhBufHS1, 
	TgWhBufHS1, 
	SeOutAvHS1, 
	LdProgHS1, 
	Mode2HS1, 
	ReRtTSHS1, 
	ShftIRHS1, 
	NewTrHS1, 
	Mode1HS1, 
	ShftORHS1, 
	ActRtHS1, 
	Mode0HS1, 
	TxHInHS1, 
	LxHInHS1, 
	NewLineHS1, 
	ActBmHS1, 
	GoBmHS1, 
	LoadOHHS1, 
	test_so, 
	SeFullOHS1, 
	GoRtHS1, 
	LoadIHHS1, 
	SeFullIHS1);
   input CK;
   input Rdy1RtHS1;
   input Rdy2RtHS1;
   input Rdy1BmHS1;
   input Rdy2BmHS1;
   input InDoneHS1;
   input RtTSHS1;
   input TpArrayHS1;
   input OutputHS1;
   input WantBmHS1;
   input WantRtHS1;
   input OutAvHS1;
   input FullOHS1;
   input FullIHS1;
   input Prog_2;
   input Prog_1;
   input Prog_0;
   input test_se;
   input test_si;
   output ReWhBufHS1;
   output TgWhBufHS1;
   output SeOutAvHS1;
   output LdProgHS1;
   output Mode2HS1;
   output ReRtTSHS1;
   output ShftIRHS1;
   output NewTrHS1;
   output Mode1HS1;
   output ShftORHS1;
   output ActRtHS1;
   output Mode0HS1;
   output TxHInHS1;
   output LxHInHS1;
   output NewLineHS1;
   output ActBmHS1;
   output GoBmHS1;
   output LoadOHHS1;
   output test_so;
   output SeFullOHS1;
   output GoRtHS1;
   output LoadIHHS1;
   output SeFullIHS1;

   // Internal wires
   wire I265;
   wire I266;
   wire I263;
   wire I264;
   wire I271;
   wire I272;
   wire I284;
   wire I283;
   wire I282;
   wire I275;
   wire I274;
   wire State_0;
   wire I281;
   wire State_1;
   wire I280;
   wire State_2;
   wire I279;
   wire State_3;
   wire I278;
   wire State_4;
   wire I277;
   wire State_5;
   wire I276;
   wire I269;
   wire I267;
   wire I345;
   wire I344;
   wire I326;
   wire I327;
   wire I624;
   wire I625;
   wire I495;
   wire I494;
   wire I512;
   wire I513;
   wire I509;
   wire I508;
   wire I570;
   wire I571;
   wire I330;
   wire I331;
   wire I440;
   wire I441;
   wire I505;
   wire I504;
   wire I338;
   wire I339;
   wire I343;
   wire I342;
   wire I425;
   wire I424;
   wire I487;
   wire I486;
   wire I436;
   wire I437;
   wire I450;
   wire I451;
   wire I458;
   wire I459;
   wire I534;
   wire I535;
   wire I555;
   wire I554;
   wire I391;
   wire I390;
   wire I340;
   wire I341;
   wire I396;
   wire I397;
   wire I414;
   wire I415;
   wire I468;
   wire I469;
   wire I323;
   wire I16;
   wire I399;
   wire I398;
   wire I429;
   wire I428;
   wire I453;
   wire I452;
   wire I445;
   wire I444;
   wire I381;
   wire I380;
   wire I13;
   wire I366;
   wire I367;
   wire I474;
   wire I475;
   wire I430;
   wire I431;
   wire I434;
   wire I435;
   wire I466;
   wire I467;
   wire I371;
   wire I370;
   wire I376;
   wire I377;
   wire I359;
   wire I358;
   wire I553;
   wire I552;
   wire I567;
   wire I566;
   wire I411;
   wire I410;
   wire I354;
   wire I355;
   wire I362;
   wire I363;
   wire I378;
   wire I379;
   wire I422;
   wire I423;
   wire I328;
   wire I329;
   wire I295;
   wire I18;
   wire I447;
   wire I446;
   wire I770;
   wire I771;
   wire I690;
   wire I691;
   wire I768;
   wire I769;
   wire I476;
   wire I477;
   wire I404;
   wire I405;
   wire I660;
   wire I661;
   wire I297;
   wire I20;
   wire I662;
   wire I663;
   wire I294;
   wire I17;
   wire I350;
   wire I351;
   wire I778;
   wire I779;
   wire I311;
   wire I7;
   wire I287;
   wire I10;
   wire I300;
   wire I23;
   wire I303;
   wire I26;
   wire I840_2;
   wire I873_1;
   wire I840_1;
   wire I610;
   wire I612;
   wire I850_1;
   wire I335;
   wire I963_1;
   wire I357;
   wire I966_1;
   wire I325;
   wire I1025_1;
   wire I360;
   wire I910_1;
   wire I614;
   wire I850_2;
   wire I497;
   wire I1044_1;
   wire I1077_1;
   wire I506;
   wire I1083_1;
   wire I393;
   wire I1170_1;
   wire I521;
   wire I1193_1;
   wire I1184_1;
   wire I382;
   wire I1080_1;
   wire I1107_1;
   wire I418;
   wire I1103_1;
   wire I1196_1;
   wire I1040_1;
   wire I1103_2;
   wire I1180_1;
   wire I317;
   wire I1031_1;
   wire I529;
   wire I1166_1;
   wire I412;
   wire I1160_1;
   wire I1034_1;
   wire I531;
   wire I1163_1;
   wire I590;
   wire I1136_1;
   wire I1166_2;
   wire I1173_1;
   wire I388;
   wire I1110_1;
   wire I1188_2;
   wire I1199_2;
   wire I580;
   wire I789_1;
   wire I1184_2;
   wire I1188_1;
   wire I596;
   wire I1143_2;
   wire I384;
   wire I1100_1;
   wire I568;
   wire I1128_1;
   wire I1056_1;
   wire I1176_1;
   wire I556;
   wire I1097_1;
   wire I348;
   wire I1180_2;
   wire I600;
   wire I1176_2;
   wire I364;
   wire I562;
   wire I810_1;
   wire I1199_1;
   wire I353;
   wire I1143_1;
   wire I573;
   wire I1140_1;
   wire I582;
   wire I1094_1;
   wire I1047_2;
   wire I881_1;
   wire I1047_1;
   wire I881_2;
   wire I493;
   wire I857_1;
   wire I523;
   wire I834_1;
   wire I892_1;
   wire I336;
   wire I1037_1;
   wire I457;
   wire I861_2;
   wire I892_2;
   wire I320;
   wire I896_1;
   wire I455;
   wire I861_1;
   wire I589;
   wire I1121_1;
   wire I796_1;
   wire I543;
   wire I577;
   wire I1203_2;
   wire I449;
   wire I537;
   wire I1216_1;
   wire I1113_1;
   wire I479;
   wire I1118_1;
   wire I463;
   wire I491;
   wire I1203_1;
   wire I465;
   wire I489;
   wire I1216_2;
   wire I1154_1;
   wire I1028_1;
   wire I593;
   wire I595;
   wire I1132_1;
   wire I1132_2;
   wire I565;
   wire I1148_1;
   wire I559;
   wire I1121_2;
   wire I561;
   wire I1125_1;
   wire I526;
   wire I1087_1;
   wire I814_1;
   wire I599;
   wire I1157_1;
   wire I421;
   wire I1210_1;
   wire I585;
   wire I587;
   wire I1091_1;
   wire I547;
   wire I575;
   wire I829_1;
   wire I498;
   wire I1213_1;
   wire I519;
   wire I579;
   wire I1207_1;
   wire I1151_1;
   wire I511;
   wire I473;
   wire I539;
   wire I525;
   wire I514;
   wire I439;
   wire I461;
   wire I318;
   wire I394;
   wire I482;
   wire I372;
   wire I374;
   wire I548;
   wire I485;
   wire I503;
   wire I442;
   wire I551;
   wire I481;
   wire I680;
   wire I532;
   wire I407;
   wire I432;
   wire I500;
   wire I634;
   wire I403;
   wire I609;
   wire I416;
   wire I19;
   wire I676;
   wire I682;
   wire I738;
   wire I746;
   wire I706;
   wire I12;
   wire I545;
   wire I517;
   wire I715;
   wire I713;
   wire I719;
   wire I717;
   wire I675;
   wire I15;
   wire I725;
   wire I4;
   wire I733;
   wire I729;
   wire I731;
   wire I5;
   wire I702;
   wire I684;
   wire I686;
   wire I678;
   wire I655;
   wire I657;
   wire I8;
   wire I671;
   wire I673;
   wire I14;
   wire I742;
   wire I689;
   wire I693;
   wire I21;
   wire I711;
   wire I2;
   wire I659;
   wire I9;
   wire I669;
   wire I667;
   wire I11;
   wire I744;
   wire I740;
   wire I721;
   wire I723;
   wire I3;
   wire I737;
   wire I735;
   wire I704;
   wire I699;
   wire I695;
   wire I697;
   wire I22;
   wire I665;
   wire I750;
   wire I30;
   wire I700;
   wire I708;
   wire I777;
   wire I6;
   wire I767;
   wire I25;
   wire I28;
   wire I27;
   wire I24;
   wire I386;
   wire I315;
   wire I347;
   wire I470;
   wire I333;
   wire I29;
   wire I540;
   wire I408;

   INV_X1 U_I265 (.ZN(I265), 
	.A(Rdy1BmHS1));
   INV_X1 U_I266 (.ZN(I266), 
	.A(Rdy2BmHS1));
   INV_X1 U_I263 (.ZN(I263), 
	.A(Rdy1RtHS1));
   INV_X1 U_I264 (.ZN(I264), 
	.A(Rdy2RtHS1));
   INV_X1 U_I271 (.ZN(I271), 
	.A(WantBmHS1));
   INV_X1 U_I272 (.ZN(I272), 
	.A(WantRtHS1));
   INV_X1 U_I284 (.ZN(I284), 
	.A(Prog_0));
   INV_X1 U_I283 (.ZN(I283), 
	.A(Prog_1));
   INV_X1 U_I282 (.ZN(I282), 
	.A(Prog_2));
   INV_X1 U_I275 (.ZN(I275), 
	.A(FullIHS1));
   INV_X1 U_I274 (.ZN(I274), 
	.A(FullOHS1));
   INV_X1 U_I281 (.ZN(I281), 
	.A(State_0));
   INV_X1 U_I280 (.ZN(I280), 
	.A(State_1));
   INV_X1 U_I279 (.ZN(I279), 
	.A(State_2));
   INV_X1 U_I278 (.ZN(I278), 
	.A(State_3));
   INV_X1 U_I277 (.ZN(I277), 
	.A(State_4));
   INV_X1 U_I276 (.ZN(I276), 
	.A(State_5));
   INV_X1 U_I269 (.ZN(I269), 
	.A(TpArrayHS1));
   INV_X1 U_I267 (.ZN(I267), 
	.A(InDoneHS1));
   INV_X1 U_I344 (.ZN(I344), 
	.A(I345));
   INV_X1 U_I327 (.ZN(I327), 
	.A(I326));
   INV_X1 U_I625 (.ZN(I625), 
	.A(I624));
   INV_X1 U_I494 (.ZN(I494), 
	.A(I495));
   INV_X1 U_I513 (.ZN(I513), 
	.A(I512));
   INV_X1 U_I508 (.ZN(I508), 
	.A(I509));
   INV_X1 U_I571 (.ZN(I571), 
	.A(I570));
   INV_X1 U_I331 (.ZN(I331), 
	.A(I330));
   INV_X1 U_I441 (.ZN(I441), 
	.A(I440));
   INV_X1 U_I504 (.ZN(I504), 
	.A(I505));
   INV_X1 U_I339 (.ZN(I339), 
	.A(I338));
   INV_X1 U_I342 (.ZN(I342), 
	.A(I343));
   INV_X1 U_I424 (.ZN(I424), 
	.A(I425));
   INV_X1 U_I486 (.ZN(I486), 
	.A(I487));
   INV_X1 U_I437 (.ZN(I437), 
	.A(I436));
   INV_X1 U_I451 (.ZN(I451), 
	.A(I450));
   INV_X1 U_I459 (.ZN(I459), 
	.A(I458));
   INV_X1 U_I535 (.ZN(I535), 
	.A(I534));
   INV_X1 U_I554 (.ZN(I554), 
	.A(I555));
   INV_X1 U_I390 (.ZN(I390), 
	.A(I391));
   INV_X1 U_I341 (.ZN(I341), 
	.A(I340));
   INV_X1 U_I397 (.ZN(I397), 
	.A(I396));
   INV_X1 U_I415 (.ZN(I415), 
	.A(I414));
   INV_X1 U_I469 (.ZN(I469), 
	.A(I468));
   INV_X1 U_I16 (.ZN(I16), 
	.A(I323));
   INV_X1 U_I398 (.ZN(I398), 
	.A(I399));
   INV_X1 U_I428 (.ZN(I428), 
	.A(I429));
   INV_X1 U_I452 (.ZN(I452), 
	.A(I453));
   INV_X1 U_I444 (.ZN(I444), 
	.A(I445));
   INV_X1 U_I380 (.ZN(I380), 
	.A(I381));
   INV_X1 U_I13 (.ZN(I13), 
	.A(I415));
   INV_X1 U_I367 (.ZN(I367), 
	.A(I366));
   INV_X1 U_I475 (.ZN(I475), 
	.A(I474));
   INV_X1 U_I431 (.ZN(I431), 
	.A(I430));
   INV_X1 U_I435 (.ZN(I435), 
	.A(I434));
   INV_X1 U_I467 (.ZN(I467), 
	.A(I466));
   INV_X1 U_I370 (.ZN(I370), 
	.A(I371));
   INV_X1 U_I377 (.ZN(I377), 
	.A(I376));
   INV_X1 U_I358 (.ZN(I358), 
	.A(I359));
   INV_X1 U_I552 (.ZN(I552), 
	.A(I553));
   INV_X1 U_I566 (.ZN(I566), 
	.A(I567));
   INV_X1 U_I410 (.ZN(I410), 
	.A(I411));
   INV_X1 U_I355 (.ZN(I355), 
	.A(I354));
   INV_X1 U_I363 (.ZN(I363), 
	.A(I362));
   INV_X1 U_I379 (.ZN(I379), 
	.A(I378));
   INV_X1 U_I423 (.ZN(I423), 
	.A(I422));
   INV_X1 U_I329 (.ZN(I329), 
	.A(I328));
   INV_X1 U_I18 (.ZN(I18), 
	.A(I295));
   INV_X1 U_I446 (.ZN(I446), 
	.A(I447));
   INV_X1 U_I771 (.ZN(I771), 
	.A(I770));
   INV_X1 U_I691 (.ZN(I691), 
	.A(I690));
   INV_X1 U_I769 (.ZN(I769), 
	.A(I768));
   INV_X1 U_I477 (.ZN(I477), 
	.A(I476));
   INV_X1 U_I405 (.ZN(I405), 
	.A(I404));
   INV_X1 U_I661 (.ZN(I661), 
	.A(I660));
   INV_X1 U_I20 (.ZN(I20), 
	.A(I297));
   INV_X1 U_I663 (.ZN(I663), 
	.A(I662));
   INV_X1 U_I17 (.ZN(I17), 
	.A(I294));
   INV_X1 U_I351 (.ZN(I351), 
	.A(I350));
   INV_X1 U_I779 (.ZN(I779), 
	.A(I778));
   INV_X1 U_I7 (.ZN(I7), 
	.A(I311));
   INV_X1 U_I10 (.ZN(I10), 
	.A(I287));
   INV_X1 U_I23 (.ZN(I23), 
	.A(I300));
   INV_X1 U_I26 (.ZN(I26), 
	.A(I303));
   AND2_X1 U_I840_2 (.ZN(I840_2), 
	.A2(Prog_0), 
	.A1(Prog_1));
   AND2_X1 U_I873_1 (.ZN(I873_1), 
	.A2(I264), 
	.A1(I263));
   AND2_X1 U_I840_1 (.ZN(I840_1), 
	.A2(I284), 
	.A1(I283));
   AND2_X1 U_I850_1 (.ZN(I850_1), 
	.A2(I612), 
	.A1(I610));
   AND2_X1 U_I963_1 (.ZN(I963_1), 
	.A2(I345), 
	.A1(I335));
   AND2_X1 U_I966_1 (.ZN(I966_1), 
	.A2(I357), 
	.A1(I335));
   AND2_X1 U_I1025_1 (.ZN(I1025_1), 
	.A2(I325), 
	.A1(Rdy2BmHS1));
   AND2_X1 U_I910_1 (.ZN(I910_1), 
	.A2(I360), 
	.A1(I277));
   AND2_X1 U_I850_2 (.ZN(I850_2), 
	.A2(I614), 
	.A1(WantRtHS1));
   AND2_X1 U_I1044_1 (.ZN(I1044_1), 
	.A2(I570), 
	.A1(I497));
   AND2_X1 U_I1077_1 (.ZN(I1077_1), 
	.A2(I512), 
	.A1(I458));
   AND2_X1 U_I1083_1 (.ZN(I1083_1), 
	.A2(I506), 
	.A1(I458));
   AND2_X1 U_I1170_1 (.ZN(I1170_1), 
	.A2(I414), 
	.A1(I393));
   AND2_X1 U_I1193_1 (.ZN(I1193_1), 
	.A2(I521), 
	.A1(I424));
   AND2_X1 U_I1184_1 (.ZN(I1184_1), 
	.A2(I506), 
	.A1(I486));
   AND2_X1 U_I1080_1 (.ZN(I1080_1), 
	.A2(I382), 
	.A1(Prog_0));
   AND2_X1 U_I1107_1 (.ZN(I1107_1), 
	.A2(I382), 
	.A1(I284));
   AND2_X1 U_I1103_1 (.ZN(I1103_1), 
	.A2(I418), 
	.A1(State_5));
   AND2_X1 U_I1196_1 (.ZN(I1196_1), 
	.A2(I418), 
	.A1(I345));
   AND2_X1 U_I1040_1 (.ZN(I1040_1), 
	.A2(I16), 
	.A1(OutputHS1));
   AND2_X1 U_I1103_2 (.ZN(I1103_2), 
	.A2(I16), 
	.A1(Prog_0));
   AND2_X1 U_I1180_1 (.ZN(I1180_1), 
	.A2(I16), 
	.A1(I267));
   AND2_X1 U_I1031_1 (.ZN(I1031_1), 
	.A2(I398), 
	.A1(I317));
   AND2_X1 U_I1166_1 (.ZN(I1166_1), 
	.A2(I529), 
	.A1(I357));
   AND2_X1 U_I1160_1 (.ZN(I1160_1), 
	.A2(I412), 
	.A1(I281));
   AND2_X1 U_I1034_1 (.ZN(I1034_1), 
	.A2(I428), 
	.A1(I317));
   AND2_X1 U_I1163_1 (.ZN(I1163_1), 
	.A2(I531), 
	.A1(I345));
   AND2_X1 U_I1136_1 (.ZN(I1136_1), 
	.A2(I590), 
	.A1(I282));
   AND2_X1 U_I1166_2 (.ZN(I1166_2), 
	.A2(I452), 
	.A1(Prog_2));
   AND2_X1 U_I1173_1 (.ZN(I1173_1), 
	.A2(I466), 
	.A1(I263));
   AND2_X1 U_I1110_1 (.ZN(I1110_1), 
	.A2(I388), 
	.A1(I277));
   AND2_X1 U_I1188_2 (.ZN(I1188_2), 
	.A2(I388), 
	.A1(I267));
   AND2_X1 U_I1199_2 (.ZN(I1199_2), 
	.A2(I380), 
	.A1(I267));
   AND2_X1 U_I789_1 (.ZN(I789_1), 
	.A2(I580), 
	.A1(I278));
   AND2_X1 U_I1184_2 (.ZN(I1184_2), 
	.A2(I376), 
	.A1(I269));
   AND2_X1 U_I1188_1 (.ZN(I1188_1), 
	.A2(I376), 
	.A1(State_1));
   AND2_X1 U_I1143_2 (.ZN(I1143_2), 
	.A2(I596), 
	.A1(I274));
   AND2_X1 U_I1100_1 (.ZN(I1100_1), 
	.A2(I384), 
	.A1(WantBmHS1));
   AND2_X1 U_I1128_1 (.ZN(I1128_1), 
	.A2(I568), 
	.A1(I378));
   AND2_X1 U_I1056_1 (.ZN(I1056_1), 
	.A2(I358), 
	.A1(I280));
   AND2_X1 U_I1176_1 (.ZN(I1176_1), 
	.A2(I566), 
	.A1(State_4));
   AND2_X1 U_I1097_1 (.ZN(I1097_1), 
	.A2(I556), 
	.A1(I317));
   AND2_X1 U_I1180_2 (.ZN(I1180_2), 
	.A2(I554), 
	.A1(I348));
   AND2_X1 U_I1176_2 (.ZN(I1176_2), 
	.A2(I600), 
	.A1(Prog_0));
   AND2_X1 U_I810_1 (.ZN(I810_1), 
	.A2(I562), 
	.A1(I364));
   AND2_X1 U_I1199_1 (.ZN(I1199_1), 
	.A2(I364), 
	.A1(I338));
   AND2_X1 U_I1143_1 (.ZN(I1143_1), 
	.A2(I404), 
	.A1(I353));
   AND2_X1 U_I1140_1 (.ZN(I1140_1), 
	.A2(I573), 
	.A1(I271));
   AND2_X1 U_I1094_1 (.ZN(I1094_1), 
	.A2(I582), 
	.A1(WantRtHS1));
   OR2_X1 U_I1047_2 (.ZN(I1047_2), 
	.A2(Prog_0), 
	.A1(Rdy1BmHS1));
   OR2_X1 U_I881_1 (.ZN(I881_1), 
	.A2(Prog_2), 
	.A1(InDoneHS1));
   OR2_X1 U_I1047_1 (.ZN(I1047_1), 
	.A2(I284), 
	.A1(I264));
   OR2_X1 U_I881_2 (.ZN(I881_2), 
	.A2(I326), 
	.A1(I282));
   OR2_X1 U_I857_1 (.ZN(I857_1), 
	.A2(I493), 
	.A1(Prog_0));
   OR2_X1 U_I834_1 (.ZN(I834_1), 
	.A2(I523), 
	.A1(FullIHS1));
   OR2_X1 U_I892_1 (.ZN(I892_1), 
	.A2(I495), 
	.A1(I279));
   OR2_X1 U_I1037_1 (.ZN(I1037_1), 
	.A2(I336), 
	.A1(Prog_0));
   OR2_X1 U_I861_2 (.ZN(I861_2), 
	.A2(I457), 
	.A1(I265));
   OR2_X1 U_I892_2 (.ZN(I892_2), 
	.A2(I625), 
	.A1(I269));
   OR2_X1 U_I896_1 (.ZN(I896_1), 
	.A2(I320), 
	.A1(I279));
   OR2_X1 U_I861_1 (.ZN(I861_1), 
	.A2(I455), 
	.A1(I263));
   OR2_X1 U_I1121_1 (.ZN(I1121_1), 
	.A2(I589), 
	.A1(State_0));
   OR2_X1 U_I796_1 (.ZN(I796_1), 
	.A2(I323), 
	.A1(I283));
   OR2_X1 U_I1203_2 (.ZN(I1203_2), 
	.A2(I577), 
	.A1(I543));
   OR2_X1 U_I1216_1 (.ZN(I1216_1), 
	.A2(I537), 
	.A1(I449));
   OR2_X1 U_I1113_1 (.ZN(I1113_1), 
	.A2(I415), 
	.A1(I282));
   OR2_X1 U_I1118_1 (.ZN(I1118_1), 
	.A2(I479), 
	.A1(State_1));
   OR2_X1 U_I1203_1 (.ZN(I1203_1), 
	.A2(I491), 
	.A1(I463));
   OR2_X1 U_I1216_2 (.ZN(I1216_2), 
	.A2(I489), 
	.A1(I465));
   OR2_X1 U_I1154_1 (.ZN(I1154_1), 
	.A2(I371), 
	.A1(I267));
   OR2_X1 U_I1028_1 (.ZN(I1028_1), 
	.A2(I493), 
	.A1(I367));
   OR2_X1 U_I1132_1 (.ZN(I1132_1), 
	.A2(I595), 
	.A1(I593));
   OR2_X1 U_I1132_2 (.ZN(I1132_2), 
	.A2(I467), 
	.A1(I281));
   OR2_X1 U_I1148_1 (.ZN(I1148_1), 
	.A2(I565), 
	.A1(I267));
   OR2_X1 U_I1121_2 (.ZN(I1121_2), 
	.A2(I559), 
	.A1(Rdy2BmHS1));
   OR2_X1 U_I1125_1 (.ZN(I1125_1), 
	.A2(I561), 
	.A1(Rdy2RtHS1));
   OR2_X1 U_I1087_1 (.ZN(I1087_1), 
	.A2(I526), 
	.A1(Prog_0));
   OR2_X1 U_I814_1 (.ZN(I814_1), 
	.A2(I355), 
	.A1(FullOHS1));
   OR2_X1 U_I1157_1 (.ZN(I1157_1), 
	.A2(I599), 
	.A1(I274));
   OR2_X1 U_I1210_1 (.ZN(I1210_1), 
	.A2(I421), 
	.A1(I339));
   OR2_X1 U_I1091_1 (.ZN(I1091_1), 
	.A2(I587), 
	.A1(I585));
   OR2_X1 U_I829_1 (.ZN(I829_1), 
	.A2(I575), 
	.A1(I547));
   OR2_X1 U_I1213_1 (.ZN(I1213_1), 
	.A2(I547), 
	.A1(I498));
   OR2_X1 U_I1207_1 (.ZN(I1207_1), 
	.A2(I579), 
	.A1(I519));
   OR2_X1 U_I1151_1 (.ZN(I1151_1), 
	.A2(I537), 
	.A1(I405));
   NAND2_X1 U_I357 (.ZN(I357), 
	.A2(Rdy2BmHS1), 
	.A1(Rdy1BmHS1));
   NAND2_X1 U_I345 (.ZN(I345), 
	.A2(Rdy2RtHS1), 
	.A1(Rdy1RtHS1));
   NAND2_X1 U_I519 (.ZN(I519), 
	.A2(WantBmHS1), 
	.A1(Rdy2BmHS1));
   NAND2_X1 U_I317 (.ZN(I317), 
	.A2(FullIHS1), 
	.A1(FullOHS1));
   NAND2_X1 U_I511 (.ZN(I511), 
	.A2(State_0), 
	.A1(State_1));
   NAND2_X1 U_I543 (.ZN(I543), 
	.A2(Rdy2BmHS1), 
	.A1(I265));
   NAND2_X1 U_I473 (.ZN(I473), 
	.A2(I266), 
	.A1(I265));
   NAND2_X1 U_I493 (.ZN(I493), 
	.A2(I266), 
	.A1(Rdy1BmHS1));
   NAND2_X1 U_I537 (.ZN(I537), 
	.A2(Rdy2RtHS1), 
	.A1(I263));
   NAND2_X1 U_I575 (.ZN(I575), 
	.A2(I284), 
	.A1(I271));
   NAND2_X1 U_I393 (.ZN(I393), 
	.A2(I283), 
	.A1(I282));
   NAND2_X1 U_I587 (.ZN(I587), 
	.A2(I317), 
	.A1(Prog_0));
   NAND2_X1 U_I523 (.ZN(I523), 
	.A2(Prog_2), 
	.A1(I274));
   NAND2_X1 U_I539 (.ZN(I539), 
	.A2(I274), 
	.A1(I263));
   NAND2_X1 U_I595 (.ZN(I595), 
	.A2(I274), 
	.A1(Rdy2BmHS1));
   NAND2_X1 U_I495 (.ZN(I495), 
	.A2(I281), 
	.A1(I280));
   NAND2_X1 U_I521 (.ZN(I521), 
	.A2(I278), 
	.A1(RtTSHS1));
   NAND2_X1 U_I335 (.ZN(I335), 
	.A2(I282), 
	.A1(I277));
   NAND2_X1 U_I525 (.ZN(I525), 
	.A2(I280), 
	.A1(I277));
   NAND2_X1 U_I509 (.ZN(I509), 
	.A2(I277), 
	.A1(I276));
   NAND2_X1 U_I336 (.ZN(I336), 
	.A2(I357), 
	.A1(I473));
   NAND2_X1 U_I330 (.ZN(I330), 
	.A2(I493), 
	.A1(WantBmHS1));
   NAND2_X1 U_I439 (.ZN(I439), 
	.A2(I514), 
	.A1(Prog_0));
   NAND2_X1 U_I568 (.ZN(I568), 
	.A2(I1047_2), 
	.A1(I1047_1));
   NAND2_X1 U_I360 (.ZN(I360), 
	.A2(I881_2), 
	.A1(I881_1));
   NAND2_X1 U_I457 (.ZN(I457), 
	.A2(I506), 
	.A1(I266));
   NAND2_X1 U_I461 (.ZN(I461), 
	.A2(I506), 
	.A1(I282));
   NAND2_X1 U_I320 (.ZN(I320), 
	.A2(I511), 
	.A1(I495));
   NAND2_X1 U_I455 (.ZN(I455), 
	.A2(I512), 
	.A1(I264));
   NAND2_X1 U_I489 (.ZN(I489), 
	.A2(I570), 
	.A1(I506));
   NAND2_X1 U_I505 (.ZN(I505), 
	.A2(I570), 
	.A1(I279));
   NAND2_X1 U_I338 (.ZN(I338), 
	.A2(I439), 
	.A1(I857_1));
   NAND2_X1 U_I318 (.ZN(I318), 
	.A2(I277), 
	.A1(I834_1));
   NAND2_X1 U_I497 (.ZN(I497), 
	.A2(I457), 
	.A1(I455));
   NAND3_X1 U_I343 (.ZN(I343), 
	.A3(I482), 
	.A2(I394), 
	.A1(I276));
   NAND2_X1 U_I589 (.ZN(I589), 
	.A2(I482), 
	.A1(Prog_2));
   NAND3_X1 U_I425 (.ZN(I425), 
	.A3(I508), 
	.A2(I281), 
	.A1(State_2));
   NAND2_X1 U_I487 (.ZN(I487), 
	.A2(I508), 
	.A1(State_3));
   NAND2_X1 U_I562 (.ZN(I562), 
	.A2(I439), 
	.A1(I1037_1));
   NAND2_X1 U_I372 (.ZN(I372), 
	.A2(I892_2), 
	.A1(I892_1));
   NAND2_X1 U_I374 (.ZN(I374), 
	.A2(I461), 
	.A1(I896_1));
   NAND2_X1 U_I340 (.ZN(I340), 
	.A2(I861_2), 
	.A1(I861_1));
   NAND2_X1 U_I485 (.ZN(I485), 
	.A2(I548), 
	.A1(I277));
   NAND2_X1 U_I491 (.ZN(I491), 
	.A2(I548), 
	.A1(State_5));
   NAND3_X1 U_I323 (.ZN(I323), 
	.A3(I436), 
	.A2(I281), 
	.A1(State_4));
   NAND2_X1 U_I399 (.ZN(I399), 
	.A2(I436), 
	.A1(I284));
   NAND3_X1 U_I577 (.ZN(I577), 
	.A3(I436), 
	.A2(I318), 
	.A1(State_0));
   NAND2_X1 U_I429 (.ZN(I429), 
	.A2(I450), 
	.A1(Prog_0));
   NAND3_X1 U_I449 (.ZN(I449), 
	.A3(I450), 
	.A2(I318), 
	.A1(State_1));
   NAND3_X1 U_I453 (.ZN(I453), 
	.A3(I504), 
	.A2(I327), 
	.A1(I277));
   NAND2_X1 U_I503 (.ZN(I503), 
	.A2(I504), 
	.A1(I277));
   NAND2_X1 U_I551 (.ZN(I551), 
	.A2(I442), 
	.A1(I279));
   NAND2_X1 U_I445 (.ZN(I445), 
	.A2(I534), 
	.A1(I374));
   NAND2_X1 U_I381 (.ZN(I381), 
	.A2(I396), 
	.A1(State_3));
   NAND2_X1 U_I479 (.ZN(I479), 
	.A2(I486), 
	.A1(I279));
   NAND2_X1 U_I481 (.ZN(I481), 
	.A2(I486), 
	.A1(I372));
   NAND2_X1 U_I529 (.ZN(I529), 
	.A2(I489), 
	.A1(I399));
   NAND2_X1 U_I531 (.ZN(I531), 
	.A2(I491), 
	.A1(I429));
   NAND2_X1 U_I371 (.ZN(I371), 
	.A2(I382), 
	.A1(I279));
   NAND2_X1 U_I680 (.ZN(I680), 
	.A2(I381), 
	.A1(I445));
   NAND2_X1 U_I407 (.ZN(I407), 
	.A2(I532), 
	.A1(I412));
   NAND2_X1 U_I593 (.ZN(I593), 
	.A2(I430), 
	.A1(I284));
   NAND3_X1 U_I359 (.ZN(I359), 
	.A3(I532), 
	.A2(I432), 
	.A1(Rdy1RtHS1));
   NAND2_X1 U_I553 (.ZN(I553), 
	.A2(I500), 
	.A1(State_1));
   NAND3_X1 U_I403 (.ZN(I403), 
	.A3(I494), 
	.A2(I434), 
	.A1(I634));
   NAND2_X1 U_I609 (.ZN(I609), 
	.A2(I434), 
	.A1(I265));
   NAND3_X1 U_I411 (.ZN(I411), 
	.A3(I416), 
	.A2(Prog_0), 
	.A1(I279));
   NAND2_X1 U_I19 (.ZN(I19), 
	.A2(I323), 
	.A1(I371));
   NAND2_X1 U_I676 (.ZN(I676), 
	.A2(I343), 
	.A1(I1113_1));
   NAND2_X1 U_I682 (.ZN(I682), 
	.A2(I323), 
	.A1(I1118_1));
   NAND2_X1 U_I738 (.ZN(I738), 
	.A2(I1203_2), 
	.A1(I1203_1));
   NAND2_X1 U_I746 (.ZN(I746), 
	.A2(I1216_2), 
	.A1(I1216_1));
   NAND2_X1 U_I706 (.ZN(I706), 
	.A2(I403), 
	.A1(I1154_1));
   NAND2_X1 U_I12 (.ZN(I12), 
	.A2(I469), 
	.A1(I377));
   NAND2_X1 U_I599 (.ZN(I599), 
	.A2(I354), 
	.A1(I275));
   NAND2_X1 U_I447 (.ZN(I447), 
	.A2(I362), 
	.A1(Rdy2RtHS1));
   NAND2_X1 U_I545 (.ZN(I545), 
	.A2(I362), 
	.A1(I272));
   NAND2_X1 U_I421 (.ZN(I421), 
	.A2(I422), 
	.A1(I274));
   NAND2_X1 U_I585 (.ZN(I585), 
	.A2(I422), 
	.A1(I353));
   NAND2_X1 U_I517 (.ZN(I517), 
	.A2(I358), 
	.A1(I264));
   NAND2_X1 U_I770 (.ZN(I770), 
	.A2(I713), 
	.A1(I715));
   NAND2_X1 U_I690 (.ZN(I690), 
	.A2(I1132_2), 
	.A1(I1132_1));
   NAND2_X1 U_I768 (.ZN(I768), 
	.A2(I717), 
	.A1(I719));
   NAND2_X1 U_I15 (.ZN(I15), 
	.A2(I675), 
	.A1(I796_1));
   NAND3_X1 U_I4 (.ZN(I4), 
	.A3(I551), 
	.A2(I381), 
	.A1(I725));
   NAND4_X1 U_I5 (.ZN(I5), 
	.A4(I397), 
	.A3(I731), 
	.A2(I729), 
	.A1(I733));
   NAND2_X1 U_I702 (.ZN(I702), 
	.A2(I481), 
	.A1(I1148_1));
   NAND2_X1 U_I556 (.ZN(I556), 
	.A2(I355), 
	.A1(I1028_1));
   NAND2_X1 U_I684 (.ZN(I684), 
	.A2(I1121_2), 
	.A1(I1121_1));
   NAND2_X1 U_I686 (.ZN(I686), 
	.A2(I441), 
	.A1(I1125_1));
   NAND2_X1 U_I573 (.ZN(I573), 
	.A2(I545), 
	.A1(I517));
   NAND2_X1 U_I678 (.ZN(I678), 
	.A2(I423), 
	.A1(I329));
   NAND2_X1 U_I8 (.ZN(I8), 
	.A2(I657), 
	.A1(I655));
   NAND2_X1 U_I14 (.ZN(I14), 
	.A2(I673), 
	.A1(I671));
   NAND2_X1 U_I660 (.ZN(I660), 
	.A2(I469), 
	.A1(I1087_1));
   NAND2_X1 U_I547 (.ZN(I547), 
	.A2(I446), 
	.A1(WantRtHS1));
   NAND2_X1 U_I742 (.ZN(I742), 
	.A2(I551), 
	.A1(I1210_1));
   NAND2_X1 U_I662 (.ZN(I662), 
	.A2(I329), 
	.A1(I1091_1));
   NAND3_X1 U_I21 (.ZN(I21), 
	.A3(I691), 
	.A2(I693), 
	.A1(I689));
   NAND3_X1 U_I2 (.ZN(I2), 
	.A3(I769), 
	.A2(I771), 
	.A1(I711));
   NAND3_X1 U_I9 (.ZN(I9), 
	.A3(I659), 
	.A2(I661), 
	.A1(I377));
   NAND3_X1 U_I11 (.ZN(I11), 
	.A3(I667), 
	.A2(I669), 
	.A1(I475));
   NAND2_X1 U_I744 (.ZN(I744), 
	.A2(I553), 
	.A1(I1213_1));
   NAND2_X1 U_I740 (.ZN(I740), 
	.A2(I477), 
	.A1(I1207_1));
   NAND2_X1 U_I3 (.ZN(I3), 
	.A2(I723), 
	.A1(I721));
   NAND2_X1 U_I778 (.ZN(I778), 
	.A2(I735), 
	.A1(I737));
   NAND2_X1 U_I704 (.ZN(I704), 
	.A2(I329), 
	.A1(I1151_1));
   NAND4_X1 U_I22 (.ZN(I22), 
	.A4(I481), 
	.A3(I697), 
	.A2(I695), 
	.A1(I699));
   NAND2_X1 U_I750 (.ZN(I750), 
	.A2(I663), 
	.A1(I665));
   NAND2_X1 U_I30 (.ZN(I30), 
	.A2(I351), 
	.A1(I829_1));
   NAND2_X1 U_I700 (.ZN(I700), 
	.A2(I351), 
	.A1(I403));
   NAND2_X1 U_I708 (.ZN(I708), 
	.A2(I351), 
	.A1(I1157_1));
   NAND3_X1 U_I6 (.ZN(I6), 
	.A3(I777), 
	.A2(I779), 
	.A1(I377));
   NAND2_X1 U_I25 (.ZN(I25), 
	.A2(I767), 
	.A1(I814_1));
   NOR2_X1 U_I326 (.ZN(I326), 
	.A2(FullIHS1), 
	.A1(FullOHS1));
   NOR2_X1 U_I28 (.ZN(I28), 
	.A2(FullIHS1), 
	.A1(OutAvHS1));
   NOR2_X1 U_I514 (.ZN(I514), 
	.A2(Rdy2RtHS1), 
	.A1(I263));
   NOR2_X1 U_I610 (.ZN(I610), 
	.A2(I284), 
	.A1(Prog_2));
   NOR2_X1 U_I27 (.ZN(I27), 
	.A2(I275), 
	.A1(OutAvHS1));
   NOR2_X1 U_I24 (.ZN(I24), 
	.A2(I326), 
	.A1(OutAvHS1));
   NOR2_X1 U_I612 (.ZN(I612), 
	.A2(I274), 
	.A1(Rdy1RtHS1));
   NOR2_X1 U_I506 (.ZN(I506), 
	.A2(I281), 
	.A1(State_1));
   NOR2_X1 U_I624 (.ZN(I624), 
	.A2(I511), 
	.A1(State_2));
   NOR2_X1 U_I386 (.ZN(I386), 
	.A2(I280), 
	.A1(State_2));
   NOR2_X1 U_I512 (.ZN(I512), 
	.A2(State_0), 
	.A1(I280));
   NOR2_X1 U_I570 (.ZN(I570), 
	.A2(State_3), 
	.A1(I276));
   NOR2_X1 U_I498 (.ZN(I498), 
	.A2(I473), 
	.A1(I271));
   NOR2_X1 U_I315 (.ZN(I315), 
	.A2(I514), 
	.A1(I272));
   NOR2_X1 U_I353 (.ZN(I353), 
	.A2(I873_1), 
	.A1(I344));
   NOR2_X1 U_I325 (.ZN(I325), 
	.A2(I840_2), 
	.A1(I840_1));
   NOR3_X1 U_I394 (.ZN(I394), 
	.A3(I357), 
	.A2(I327), 
	.A1(State_0));
   NOR2_X1 U_I532 (.ZN(I532), 
	.A2(I327), 
	.A1(State_4));
   NOR2_X1 U_I614 (.ZN(I614), 
	.A2(I575), 
	.A1(I523));
   NOR3_X1 U_I482 (.ZN(I482), 
	.A3(I525), 
	.A2(State_2), 
	.A1(State_3));
   NOR2_X1 U_I440 (.ZN(I440), 
	.A2(I509), 
	.A1(I495));
   NOR2_X1 U_I347 (.ZN(I347), 
	.A2(I394), 
	.A1(State_3));
   NOR2_X1 U_I548 (.ZN(I548), 
	.A2(I513), 
	.A1(State_3));
   NOR2_X1 U_I436 (.ZN(I436), 
	.A2(I505), 
	.A1(State_1));
   NOR2_X1 U_I450 (.ZN(I450), 
	.A2(I505), 
	.A1(State_0));
   NOR2_X1 U_I458 (.ZN(I458), 
	.A2(I571), 
	.A1(I279));
   NOR3_X1 U_I470 (.ZN(I470), 
	.A3(I571), 
	.A2(I335), 
	.A1(I320));
   NOR2_X1 U_I534 (.ZN(I534), 
	.A2(I571), 
	.A1(State_4));
   NOR2_X1 U_I555 (.ZN(I555), 
	.A2(I1025_1), 
	.A1(I330));
   NOR3_X1 U_I442 (.ZN(I442), 
	.A3(I509), 
	.A2(I347), 
	.A1(State_1));
   NOR2_X1 U_I391 (.ZN(I391), 
	.A2(I910_1), 
	.A1(State_2));
   NOR2_X1 U_I333 (.ZN(I333), 
	.A2(I850_2), 
	.A1(I850_1));
   NOR3_X1 U_I29 (.ZN(I29), 
	.A3(I441), 
	.A2(State_2), 
	.A1(I278));
   NOR2_X1 U_I396 (.ZN(I396), 
	.A2(I425), 
	.A1(I280));
   NOR3_X1 U_I414 (.ZN(I414), 
	.A3(I521), 
	.A2(I425), 
	.A1(State_1));
   NOR3_X1 U_I468 (.ZN(I468), 
	.A3(I487), 
	.A2(I386), 
	.A1(State_0));
   NOR2_X1 U_I634 (.ZN(I634), 
	.A2(I333), 
	.A1(I264));
   NOR3_X1 U_I382 (.ZN(I382), 
	.A3(I485), 
	.A2(Prog_2), 
	.A1(I276));
   NOR2_X1 U_I418 (.ZN(I418), 
	.A2(I485), 
	.A1(I279));
   NOR3_X1 U_I366 (.ZN(I366), 
	.A3(I399), 
	.A2(I335), 
	.A1(State_0));
   NOR2_X1 U_I412 (.ZN(I412), 
	.A2(I437), 
	.A1(I282));
   NOR2_X1 U_I474 (.ZN(I474), 
	.A2(I577), 
	.A1(I493));
   NOR2_X1 U_I590 (.ZN(I590), 
	.A2(I539), 
	.A1(I429));
   NOR3_X1 U_I540 (.ZN(I540), 
	.A3(I449), 
	.A2(I263), 
	.A1(Rdy2RtHS1));
   NOR2_X1 U_I430 (.ZN(I430), 
	.A2(I451), 
	.A1(Prog_2));
   NOR2_X1 U_I432 (.ZN(I432), 
	.A2(I451), 
	.A1(I282));
   NOR2_X1 U_I500 (.ZN(I500), 
	.A2(I453), 
	.A1(I281));
   NOR2_X1 U_I434 (.ZN(I434), 
	.A2(I503), 
	.A1(FullIHS1));
   NOR2_X1 U_I466 (.ZN(I466), 
	.A2(I503), 
	.A1(Rdy1BmHS1));
   NOR2_X1 U_I388 (.ZN(I388), 
	.A2(I459), 
	.A1(I320));
   NOR2_X1 U_I416 (.ZN(I416), 
	.A2(I535), 
	.A1(I461));
   NOR2_X1 U_I463 (.ZN(I463), 
	.A2(I963_1), 
	.A1(I390));
   NOR2_X1 U_I465 (.ZN(I465), 
	.A2(I966_1), 
	.A1(I390));
   NOR2_X1 U_I580 (.ZN(I580), 
	.A2(I397), 
	.A1(I345));
   NOR2_X1 U_I733 (.ZN(I733), 
	.A2(I1193_1), 
	.A1(I342));
   NOR2_X1 U_I376 (.ZN(I376), 
	.A2(I479), 
	.A1(I281));
   NOR2_X1 U_I655 (.ZN(I655), 
	.A2(I1077_1), 
	.A1(I16));
   NOR2_X1 U_I659 (.ZN(I659), 
	.A2(I1083_1), 
	.A1(I16));
   NOR2_X1 U_I717 (.ZN(I717), 
	.A2(I1170_1), 
	.A1(I16));
   NOR2_X1 U_I731 (.ZN(I731), 
	.A2(I474), 
	.A1(I540));
   NOR2_X1 U_I567 (.ZN(I567), 
	.A2(I1044_1), 
	.A1(I388));
   NOR2_X1 U_I565 (.ZN(I565), 
	.A2(I1040_1), 
	.A1(I444));
   NOR2_X1 U_I671 (.ZN(I671), 
	.A2(I1103_2), 
	.A1(I1103_1));
   NOR2_X1 U_I354 (.ZN(I354), 
	.A2(I543), 
	.A1(I367));
   NOR2_X1 U_I596 (.ZN(I596), 
	.A2(I367), 
	.A1(I336));
   NOR2_X1 U_I559 (.ZN(I559), 
	.A2(I1031_1), 
	.A1(I412));
   NOR2_X1 U_I362 (.ZN(I362), 
	.A2(I407), 
	.A1(State_0));
   NOR3_X1 U_I384 (.ZN(I384), 
	.A3(I493), 
	.A2(I407), 
	.A1(I315));
   NOR2_X1 U_I711 (.ZN(I711), 
	.A2(I1160_1), 
	.A1(I388));
   NOR2_X1 U_I561 (.ZN(I561), 
	.A2(I1034_1), 
	.A1(I432));
   NOR2_X1 U_I713 (.ZN(I713), 
	.A2(I1163_1), 
	.A1(I470));
   NOR2_X1 U_I693 (.ZN(I693), 
	.A2(I1136_1), 
	.A1(I376));
   NOR2_X1 U_I378 (.ZN(I378), 
	.A2(I431), 
	.A1(FullIHS1));
   NOR2_X1 U_I422 (.ZN(I422), 
	.A2(I525), 
	.A1(I431));
   NOR2_X1 U_I715 (.ZN(I715), 
	.A2(I1166_2), 
	.A1(I1166_1));
   NOR3_X1 U_I408 (.ZN(I408), 
	.A3(I523), 
	.A2(I435), 
	.A1(I341));
   NOR3_X1 U_I328 (.ZN(I328), 
	.A3(I539), 
	.A2(I511), 
	.A1(I609));
   NOR2_X1 U_I719 (.ZN(I719), 
	.A2(I1173_1), 
	.A1(I500));
   NOR2_X1 U_I675 (.ZN(I675), 
	.A2(I1110_1), 
	.A1(I470));
   NOR2_X1 U_I526 (.ZN(I526), 
	.A2(I416), 
	.A1(I370));
   NOR2_X1 U_I725 (.ZN(I725), 
	.A2(I1184_2), 
	.A1(I1184_1));
   NOR2_X1 U_I729 (.ZN(I729), 
	.A2(I1188_2), 
	.A1(I1188_1));
   NOR3_X1 U_I295 (.ZN(I295), 
	.A3(I680), 
	.A2(I682), 
	.A1(I376));
   NOR2_X1 U_I735 (.ZN(I735), 
	.A2(I1196_1), 
	.A1(I552));
   NOR2_X1 U_I695 (.ZN(I695), 
	.A2(I328), 
	.A1(I408));
   NOR2_X1 U_I657 (.ZN(I657), 
	.A2(I1080_1), 
	.A1(I410));
   NOR2_X1 U_I673 (.ZN(I673), 
	.A2(I1107_1), 
	.A1(I410));
   NOR2_X1 U_I348 (.ZN(I348), 
	.A2(I363), 
	.A1(I315));
   NOR2_X1 U_I600 (.ZN(I600), 
	.A2(I447), 
	.A1(I331));
   NOR2_X1 U_I476 (.ZN(I476), 
	.A2(I545), 
	.A1(I519));
   NOR2_X1 U_I669 (.ZN(I669), 
	.A2(I1100_1), 
	.A1(I342));
   NOR3_X1 U_I364 (.ZN(I364), 
	.A3(I525), 
	.A2(I379), 
	.A1(I274));
   NOR2_X1 U_I689 (.ZN(I689), 
	.A2(I1128_1), 
	.A1(I440));
   NOR2_X1 U_I404 (.ZN(I404), 
	.A2(I421), 
	.A1(I284));
   NOR2_X1 U_I582 (.ZN(I582), 
	.A2(I517), 
	.A1(I331));
   NOR2_X1 U_I579 (.ZN(I579), 
	.A2(I1056_1), 
	.A1(I446));
   NOR3_X1 U_I297 (.ZN(I297), 
	.A3(I684), 
	.A2(I686), 
	.A1(I376));
   NOR3_X1 U_I294 (.ZN(I294), 
	.A3(I676), 
	.A2(I678), 
	.A1(I408));
   NOR2_X1 U_I667 (.ZN(I667), 
	.A2(I1097_1), 
	.A1(I328));
   NOR2_X1 U_I723 (.ZN(I723), 
	.A2(I1180_2), 
	.A1(I1180_1));
   NOR2_X1 U_I721 (.ZN(I721), 
	.A2(I1176_2), 
	.A1(I1176_1));
   NOR2_X1 U_I350 (.ZN(I350), 
	.A2(I477), 
	.A1(I325));
   NOR2_X1 U_I737 (.ZN(I737), 
	.A2(I1199_2), 
	.A1(I1199_1));
   NOR2_X1 U_I699 (.ZN(I699), 
	.A2(I1143_2), 
	.A1(I1143_1));
   NOR2_X1 U_I697 (.ZN(I697), 
	.A2(I1140_1), 
	.A1(I384));
   NOR2_X1 U_I665 (.ZN(I665), 
	.A2(I1094_1), 
	.A1(I540));
   NOR3_X1 U_I311 (.ZN(I311), 
	.A3(I744), 
	.A2(I746), 
	.A1(I742));
   NOR2_X1 U_I777 (.ZN(I777), 
	.A2(I738), 
	.A1(I740));
   NOR2_X1 U_I767 (.ZN(I767), 
	.A2(I702), 
	.A1(I704));
   NOR2_X1 U_I287 (.ZN(I287), 
	.A2(I789_1), 
	.A1(I750));
   NOR2_X1 U_I300 (.ZN(I300), 
	.A2(I810_1), 
	.A1(I700));
   NOR2_X1 U_I303 (.ZN(I303), 
	.A2(I708), 
	.A1(I706));
   SDFF_X1 U_State_5 (.SI(test_si), 
	.SE(test_se), 
	.Q(State_5), 
	.D(I2), 
	.CK(CK));
   SDFF_X1 U_State_4 (.SI(State_5), 
	.SE(test_se), 
	.Q(State_4), 
	.D(I3), 
	.CK(CK));
   SDFF_X1 U_State_3 (.SI(State_4), 
	.SE(test_se), 
	.Q(State_3), 
	.D(I4), 
	.CK(CK));
   SDFF_X1 U_State_2 (.SI(State_3), 
	.SE(test_se), 
	.Q(State_2), 
	.D(I5), 
	.CK(CK));
   SDFF_X1 U_State_1 (.SI(State_2), 
	.SE(test_se), 
	.Q(State_1), 
	.D(I6), 
	.CK(CK));
   SDFF_X1 U_State_0 (.SI(State_1), 
	.SE(test_se), 
	.Q(State_0), 
	.D(I7), 
	.CK(CK));
   SDFF_X1 U_ActRtHS1 (.SI(State_0), 
	.SE(test_se), 
	.Q(ActRtHS1), 
	.D(I8), 
	.CK(CK));
   SDFF_X1 U_ActBmHS1 (.SI(ActRtHS1), 
	.SE(test_se), 
	.Q(ActBmHS1), 
	.D(I9), 
	.CK(CK));
   SDFF_X1 U_GoRtHS1 (.SI(ActBmHS1), 
	.SE(test_se), 
	.Q(GoRtHS1), 
	.D(I10), 
	.CK(CK));
   SDFF_X1 U_GoBmHS1 (.SI(GoRtHS1), 
	.SE(test_se), 
	.Q(GoBmHS1), 
	.D(I11), 
	.CK(CK));
   SDFF_X1 U_NewTrHS1 (.SI(GoBmHS1), 
	.SE(test_se), 
	.Q(NewTrHS1), 
	.D(I12), 
	.CK(CK));
   SDFF_X1 U_ReRtTSHS1 (.SI(NewTrHS1), 
	.SE(test_se), 
	.Q(ReRtTSHS1), 
	.D(I13), 
	.CK(CK));
   SDFF_X1 U_Mode0HS1 (.SI(ReRtTSHS1), 
	.SE(test_se), 
	.Q(Mode0HS1), 
	.D(I14), 
	.CK(CK));
   SDFF_X1 U_Mode1HS1 (.SI(Mode0HS1), 
	.SE(test_se), 
	.Q(Mode1HS1), 
	.D(I15), 
	.CK(CK));
   SDFF_X1 U_Mode2HS1 (.SI(Mode1HS1), 
	.SE(test_se), 
	.Q(Mode2HS1), 
	.D(I16), 
	.CK(CK));
   SDFF_X1 U_NewLineHS1 (.SI(Mode2HS1), 
	.SE(test_se), 
	.Q(NewLineHS1), 
	.D(I17), 
	.CK(CK));
   SDFF_X1 U_ShftORHS1 (.SI(NewLineHS1), 
	.SE(test_se), 
	.Q(ShftORHS1), 
	.D(I18), 
	.CK(CK));
   SDFF_X1 U_ShftIRHS1 (.SI(ShftORHS1), 
	.SE(test_se), 
	.Q(ShftIRHS1), 
	.D(I19), 
	.CK(CK));
   SDFF_X1 U_LxHInHS1 (.SI(ShftIRHS1), 
	.SE(test_se), 
	.Q(LxHInHS1), 
	.D(I20), 
	.CK(CK));
   SDFF_X1 U_TxHInHS1 (.SI(LxHInHS1), 
	.SE(test_se), 
	.Q(TxHInHS1), 
	.D(I21), 
	.CK(CK));
   SDFF_X1 U_LoadOHHS1 (.SI(TxHInHS1), 
	.SE(test_se), 
	.Q(LoadOHHS1), 
	.D(I22), 
	.CK(CK));
   SDFF_X1 U_LoadIHHS1 (.SI(LoadOHHS1), 
	.SE(test_se), 
	.Q(LoadIHHS1), 
	.D(I23), 
	.CK(CK));
   SDFF_X1 U_SeOutAvHS1 (.SI(LoadIHHS1), 
	.SE(test_se), 
	.Q(SeOutAvHS1), 
	.D(I24), 
	.CK(CK));
   SDFF_X1 U_SeFullOHS1 (.SI(SeOutAvHS1), 
	.SE(test_se), 
	.Q(SeFullOHS1), 
	.D(I25), 
	.CK(CK));
   SDFF_X1 U_SeFullIHS1 (.SI(SeFullOHS1), 
	.SE(test_se), 
	.Q(SeFullIHS1), 
	.D(I26), 
	.CK(CK));
   SDFF_X1 U_TgWhBufHS1 (.SI(SeFullIHS1), 
	.SE(test_se), 
	.Q(TgWhBufHS1), 
	.D(I27), 
	.CK(CK));
   SDFF_X1 U_ReWhBufHS1 (.SI(TgWhBufHS1), 
	.SE(test_se), 
	.Q(ReWhBufHS1), 
	.D(I28), 
	.CK(CK));
   SDFF_X1 U_LdProgHS1 (.SI(ReWhBufHS1), 
	.SE(test_se), 
	.Q(LdProgHS1), 
	.D(I29), 
	.CK(CK));
   SDFF_X1 U_DumpIHS1 (.SI(LdProgHS1), 
	.SE(test_se), 
	.Q(test_so), 
	.D(I30), 
	.CK(CK));
endmodule
