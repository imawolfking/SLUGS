/*
The MIT License

Copyright (c) 2009 UCSC Autonomous Systems Lab

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

//---------------------------------------------------------------------------

#ifndef UPpalH
#define UPpalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "tinyxml.h"
#include <ComCtrls.hpp>
#include "Placemnt.hpp"
#include <Buttons.hpp>
#include "ABSMain.hpp"
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <Dialogs.hpp>
#include <Mask.hpp>
#include "apDefinitions.h"
#include "protDecoder.h"
#include "AdPort.hpp"
#include "CircBuffer.h"
#include "_GClass.hpp"
#include "AbLED.hpp"
#include "AbOpHour.hpp"
#include "AbMTrend.hpp"
#include <math.h>
#include <exception.h>
#include "AbVCInd.hpp"
#include "AbCBitBt.hpp"
#include "ToolEdit.hpp"
#include "gsDefinitions.h"
#include "WSocket.hpp"
#include "apUtils.h"
#include "AbTank.hpp"
#include "AbVBar.hpp"
#include "AbHBar.hpp"
#include "CurrEdit.hpp"
#include "OoMisc.hpp"
#include "RxCombos.hpp"
#include "RXSlider.hpp"
#include <string>
#include <limits.h>

#define  DISLIMIT      30.0


//---------------------------------------------------------------------------
class TFPpal : public TForm
{
__published:	// IDE-managed Components
    TStatusBar *StatusBar1;
    TPageControl *pc_main;
    TTabSheet *ts_ge;
    TTabSheet *ts_sensors;
        TTabSheet *ts_pid;
    TTabSheet *ts_plots;
    TPanel *Panel1;
    TLabel *Label1;
    TMemo *mm_diagnose;
    TFormStorage *FormStorage1;
    TSpeedButton *bt_clear;
    TABSDatabase *ad_main;
    TABSTable *tb_config;
    TLabel *Label2;
    TDataSource *fte_config;
    TDBEdit *DBEdit1;
    TSpeedButton *bt_mainKml;
    TStringField *tb_configkmlFile;
    TStringField *tb_configplanePathFile;
    TSmallintField *tb_configupdateRate;
    TSmallintField *tb_configtessellate;
    TLabel *Label3;
    TDBEdit *DBEdit2;
    TSpeedButton *bt_ppKml;
    TDBRadioGroup *rg_uprate;
    TDBCheckBox *DBCheckBox1;
    TSpeedButton *bt_gearth;
    TTimer *Timer1;
    TSaveDialog *od_mainKml;
    TColorBox *cb_color1;
    TLabel *Label4;
    TLabel *Label5;
    TColorBox *cb_color2;
    TTrackBar *kb_tessalate;
    TLabel *Label6;
    TLabel *Label7;
    TDBEdit *DBEdit3;
    TSpeedButton *bt_icon;
    TDBRadioGroup *rg_tail;
    TLabel *Label8;
    TDBEdit *bt_wp;
    TSpeedButton *SpeedButton3;
    TIntegerField *tb_configtrajectoryColorR;
    TIntegerField *tb_configtrajectoryColorG;
    TIntegerField *tb_configtrajectoryColorB;
    TSmallintField *tb_configtailLength;
    TIntegerField *tb_configtessalateColorR;
    TIntegerField *tb_configtessalateColorG;
    TIntegerField *tb_configtessalateColorB;
    TStringField *tb_configiconFile;
    TStringField *tb_configwaypointFile;
    TSpeedButton *bt_serial;
    TTimer *Timer2;
    TGroupBox *GroupBox1;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TLabel *Label15;
    TLabel *Label16;
    TLabel *Label17;
    TLabel *Label18;
    TStaticText *et_date;
    TStaticText *et_time;
    TStaticText *et_lat;
    TStaticText *et_lon;
    TStaticText *et_height;
    TStaticText *et_sog;
    TStaticText *et_cog;
    TStaticText *et_hdop;
    TStaticText *et_fix;
    TStaticText *et_sats;
    TGroupBox *GroupBox2;
    TLabel *Label20;
    TStaticText *et_accelx;
    TLabel *Label19;
    TStaticText *et_accely;
    TLabel *Label24;
    TStaticText *et_accelz;
    TLabel *Label21;
    TLabel *Label22;
    TLabel *Label23;
    TStaticText *et_gyrox;
    TStaticText *et_gyroy;
    TStaticText *et_gyroz;
    TLabel *Label25;
    TLabel *Label26;
    TStaticText *et_magx;
    TStaticText *et_magy;
    TLabel *Label27;
    TStaticText *et_magz;
    TGroupBox *GroupBox3;
    TDBEdit *DBEdit4;
    TLabel *Label28;
    TLabel *Label29;
    TDBEdit *DBEdit5;
    TLabel *Label30;
    TDBEdit *DBEdit6;
    TSpeedButton *bt_gspos;
    TFloatField *tb_configlatGS;
    TFloatField *tb_configlonGS;
    TFloatField *tb_configheightGS;
    TIntegerField *tb_configtessalateTransparency;
    TAbLED *ld_serial;
    TSpeedButton *bt_filter;
    TAbLED *ld_filter;
    TAbMiniTrend *mt_x;
    TAbMiniTrend *mt_y;
    TAbMiniTrend *mt_z;
    TTabSheet *ts_graphical;
    TTabSheet *ts_export;
    TAbVCInd *ai_att;
    TGroupBox *GroupBox5;
    TCheckBox *cb_inflight;
    TGroupBox *GroupBox6;
    TLabel *Label43;
    TStringField *tb_configExportLocation;
    TFilenameEdit *ed_importLog;
    TLabel *Label44;
    TSpeedButton *bt_importLog;
    TLabel *Label45;
    TFilenameEdit *ed_exportMat;
    TFilenameEdit *ed_liveLog;
    TApdComPort *cp_serial;
    TGroupBox *GroupBox9;
    TLabel *Label58;
    TLabel *Label59;
    TLabel *Label60;
    TStaticText *et_dyn;
    TStaticText *et_temp;
    TStaticText *et_sta;
    TLabel *Label52;
    TStaticText *et_timeStamp;
    TGroupBox *GroupBox10;
    TLabel *Label61;
    TLabel *Label62;
    TLabel *Label63;
    TStaticText *et_load;
    TStaticText *et_volt;
    TStaticText *et_vdetect;
    TTabSheet *tsHil;
    TGroupBox *GroupBox11;
    TLabel *et_connSend;
    TLabel *Label64;
    TLabel *Label65;
    TLabel *et_sent;
    TButton *bt_startSend;
    TButton *bt_stopSend;
    TEdit *ed_portSend;
    TEdit *ed_hostSend;
    TWSocket *skt_send;
    TGroupBox *GroupBox12;
    TLabel *DataAvailableLabel;
    TLabel *InfoLabel;
    TLabel *Label66;
    TLabel *Label67;
    TButton *StartButton;
    TButton *StopButton;
    TEdit *PortEdit;
    TEdit *ServerEdit;
    TCheckBox *AnyServerCheckBox;
    TApdComPort *cp_hil;
        TAbTank *gr_batt;
        TAbVBar *gr_height;
        TGroupBox *GroupBox13;
        TLabel *Label69;
        TLabel *Label70;
        TLabel *Label71;
        TLabel *Label72;
        TLabel *Label73;
        TStaticText *et_dt;
        TStaticText *et_dla;
        TStaticText *et_dra;
        TStaticText *et_dr;
        TStaticText *et_de;
        TAbVBar *gr_dt;
        TAbHBar *gr_dr;
        TAbVBar *gr_de;
        TAbHBar *gr_da;
        TLabel *Label74;
        TLabel *Label75;
        TLabel *Label76;
        TLabel *Label77;
    TTabSheet *ts_filter;
    TGroupBox *GroupBox4;
    TLabel *Label31;
    TLabel *Label32;
    TLabel *Label33;
    TLabel *Label40;
    TLabel *Label41;
    TLabel *Label42;
    TStaticText *et_x;
    TStaticText *et_y;
    TStaticText *et_z;
    TStaticText *et_vx;
    TStaticText *et_vy;
    TStaticText *et_vz;
    TGroupBox *GroupBox7;
    TLabel *Label46;
    TLabel *Label47;
    TLabel *Label48;
    TLabel *Label49;
    TLabel *Label50;
    TLabel *Label51;
    TStaticText *et_axb;
    TStaticText *et_ayb;
    TStaticText *et_azb;
    TStaticText *et_gxb;
    TStaticText *et_gyb;
    TStaticText *et_gzb;
    TPanel *Panel2;
    TLabel *et_warning;
    TGroupBox *GroupBox14;
    TLabel *Label78;
    TStaticText *et_fail;
        TGroupBox *gb_pid1;
        TLabel *Label88;
        TLabel *Label89;
        TLabel *Label90;
        TCurrencyEdit *ed_p1;
        TCurrencyEdit *ed_i1;
        TCurrencyEdit *ed_d1;
        TSpeedButton *bt_up1;
        TSpeedButton *bt_down1;
        TStaticText *et_p1;
    TStaticText *et_i1;
    TStaticText *et_d1;
        TGroupBox *gb_pid2;
        TLabel *Label91;
        TLabel *Label92;
        TLabel *Label93;
        TSpeedButton *bt_up2;
    TSpeedButton *bt_down2;
        TCurrencyEdit *ed_p2;
        TCurrencyEdit *ed_i2;
        TCurrencyEdit *ed_d2;
    TStaticText *et_p2;
    TStaticText *et_i2;
    TStaticText *et_d2;
        TGroupBox *gb_pid3;
        TLabel *Label94;
        TLabel *Label95;
        TLabel *Label96;
        TSpeedButton *bt_up3;
    TSpeedButton *bt_down3;
        TCurrencyEdit *ed_p3;
        TCurrencyEdit *ed_i3;
        TCurrencyEdit *ed_d3;
    TStaticText *et_p3;
    TStaticText *et_i3;
    TStaticText *et_d3;
        TGroupBox *gb_pid4;
        TLabel *Label97;
        TLabel *Label98;
        TLabel *Label99;
        TSpeedButton *bt_up4;
    TSpeedButton *bt_down4;
        TCurrencyEdit *ed_p4;
        TCurrencyEdit *ed_i4;
        TCurrencyEdit *ed_d4;
    TStaticText *et_p4;
    TStaticText *et_i4;
    TStaticText *et_d4;
        TGroupBox *gb_pid5;
        TLabel *Label100;
        TLabel *Label101;
        TLabel *Label102;
        TSpeedButton *bt_up5;
    TSpeedButton *bt_down5;
        TCurrencyEdit *ed_p5;
        TCurrencyEdit *ed_i5;
        TCurrencyEdit *ed_d5;
    TStaticText *et_p5;
    TStaticText *et_i5;
    TStaticText *et_d5;
        TGroupBox *gb_pid10;
        TLabel *Label115;
        TLabel *Label116;
        TLabel *Label117;
        TSpeedButton *bt_up10;
    TSpeedButton *bt_down10;
        TCurrencyEdit *ed_p10;
        TCurrencyEdit *ed_i10;
        TCurrencyEdit *ed_d10;
    TStaticText *et_p10;
    TStaticText *et_i10;
    TStaticText *et_d10;
    TGroupBox *GroupBox8;
    TLabel *Fl1;
    TLabel *Label53;
    TLabel *Label54;
    TLabel *Label55;
    TLabel *Label56;
    TLabel *Label57;
    TStaticText *et_fl1;
    TStaticText *et_fl2;
    TStaticText *et_fl3;
    TStaticText *et_sh1;
    TStaticText *et_sh2;
    TStaticText *et_sh3;
    TSpeedButton *bt_allpid;
    TTimer *Timer3;
        TTabSheet *TabSheet1;
        TGroupBox *gb_wp1;
        TLabel *Label118;
        TLabel *Label119;
        TLabel *Label120;
        TSpeedButton *bt_setwp1;
        TSpeedButton *bt_getwp1;
        TCurrencyEdit *ed_lat1;
        TCurrencyEdit *ed_lon1;
        TCurrencyEdit *ed_hei1;
        TStaticText *et_lat1;
        TStaticText *et_lon1;
        TStaticText *et_hei1;
        TCheckBox *cb_stat1;
        TCurrencyEdit *ed_val1;
        TGroupBox *gb_wp2;
        TLabel *Label121;
        TLabel *Label122;
        TLabel *Label123;
        TSpeedButton *bt_setwp2;
        TSpeedButton *bt_getwp2;
        TCurrencyEdit *ed_lat2;
        TCurrencyEdit *ed_lon2;
        TCurrencyEdit *ed_hei2;
        TStaticText *et_lat2;
        TStaticText *et_lon2;
        TStaticText *et_hei2;
        TCheckBox *cb_stat2;
        TCurrencyEdit *ed_val2;
        TGroupBox *gb_wp3;
        TLabel *Label124;
        TLabel *Label125;
        TLabel *Label126;
        TSpeedButton *bt_setwp3;
        TSpeedButton *bt_getwp3;
        TCurrencyEdit *ed_lat3;
        TCurrencyEdit *ed_lon3;
        TCurrencyEdit *ed_hei3;
        TStaticText *et_lat3;
        TStaticText *et_lon3;
        TStaticText *et_hei3;
        TCheckBox *cb_stat3;
        TCurrencyEdit *ed_val3;
        TGroupBox *gb_wp4;
        TLabel *Label127;
        TLabel *Label128;
        TLabel *Label129;
        TSpeedButton *bt_setwp4;
        TSpeedButton *bt_getwp4;
        TCurrencyEdit *ed_lat4;
        TCurrencyEdit *ed_lon4;
        TCurrencyEdit *ed_hei4;
        TStaticText *et_lat4;
        TStaticText *et_lon4;
        TStaticText *et_hei4;
        TCheckBox *cb_stat4;
        TCurrencyEdit *ed_val4;
        TGroupBox *gb_wp5;
        TLabel *Label130;
        TLabel *Label131;
        TLabel *Label132;
        TSpeedButton *bt_setwp5;
        TSpeedButton *bt_getwp5;
        TCurrencyEdit *ed_lat5;
        TCurrencyEdit *ed_lon5;
        TCurrencyEdit *ed_hei5;
        TStaticText *et_lat5;
        TStaticText *et_lon5;
        TStaticText *et_hei5;
        TCheckBox *cb_stat5;
        TCurrencyEdit *ed_val5;
        TGroupBox *gb_wp6;
        TLabel *Label133;
        TLabel *Label134;
        TLabel *Label135;
        TSpeedButton *bt_setwp6;
        TSpeedButton *bt_getwp6;
        TCurrencyEdit *ed_lat6;
        TCurrencyEdit *ed_lon6;
        TCurrencyEdit *ed_hei6;
        TStaticText *et_lat6;
        TStaticText *et_lon6;
        TStaticText *et_hei6;
        TCheckBox *cb_stat6;
        TCurrencyEdit *ed_val6;
        TGroupBox *gb_wp7;
        TLabel *Label136;
        TLabel *Label137;
        TLabel *Label138;
        TSpeedButton *bt_setwp7;
        TSpeedButton *bt_getwp7;
        TCurrencyEdit *ed_lat7;
        TCurrencyEdit *ed_lon7;
        TCurrencyEdit *ed_hei7;
        TStaticText *et_lat7;
        TStaticText *et_lon7;
        TStaticText *et_hei7;
        TCheckBox *cb_stat7;
        TCurrencyEdit *ed_val7;
        TGroupBox *gb_wp8;
        TLabel *Label139;
        TLabel *Label140;
        TLabel *Label141;
        TSpeedButton *bt_setwp8;
        TSpeedButton *bt_getwp8;
        TCurrencyEdit *ed_lat8;
        TCurrencyEdit *ed_lon8;
        TCurrencyEdit *ed_hei8;
        TStaticText *et_lat8;
        TStaticText *et_lon8;
        TStaticText *et_hei8;
        TCheckBox *cb_stat8;
        TCurrencyEdit *ed_val8;
        TGroupBox *gb_wp9;
        TLabel *Label142;
        TLabel *Label143;
        TLabel *Label144;
        TSpeedButton *bt_setwp9;
        TSpeedButton *bt_getwp9;
        TCurrencyEdit *ed_lat9;
        TCurrencyEdit *ed_lon9;
        TCurrencyEdit *ed_hei9;
        TStaticText *et_lat9;
        TStaticText *et_lon9;
        TStaticText *et_hei9;
        TCheckBox *cb_stat9;
        TCurrencyEdit *ed_val9;
        TGroupBox *gb_wp10;
        TLabel *Label145;
        TLabel *Label146;
        TLabel *Label147;
        TSpeedButton *bt_setwp10;
        TSpeedButton *bt_getwp10;
        TCurrencyEdit *ed_lat10;
        TCurrencyEdit *ed_lon10;
        TCurrencyEdit *ed_hei10;
        TStaticText *et_lat10;
        TStaticText *et_lon10;
        TStaticText *et_hei10;
        TCheckBox *cb_stat10;
        TCurrencyEdit *ed_val10;
        TSpeedButton *bt_allwp;
        TSpeedButton *SpeedButton33;
        TSpeedButton *bt_sendwps;
        TCheckBox *cb_repstat1;
        TStaticText *et_val1;
        TCheckBox *cb_repstat2;
        TStaticText *et_val2;
        TCheckBox *cb_repstat3;
        TStaticText *et_val3;
        TCheckBox *cb_repstat4;
        TStaticText *et_val4;
        TCheckBox *cb_repstat5;
        TStaticText *et_val5;
        TCheckBox *cb_repstat6;
        TStaticText *et_val6;
        TCheckBox *cb_repstat7;
        TStaticText *et_val7;
        TCheckBox *cb_repstat8;
        TStaticText *et_val8;
        TCheckBox *cb_repstat9;
        TStaticText *et_val9;
        TCheckBox *cb_repstat10;
        TStaticText *et_val10;
        TTabSheet *ts_commands;
        TPageControl *pc_commands;
        TTabSheet *ts_direct;
        TTabSheet *ts_wp;
        TTabSheet *ts_ptpil;
        TRadioButton *rb_manual;
    TRadioButton *rb_auto;
        TPanel *pn_status;
        TLabel *et_status;
        TRadioGroup *rg_modes;
        TPanel *pn_mode;
        TSpeedButton *bt_mode;
        TPanel *pn_config;
        TCheckBox *cb_ptpdt;
        TCheckBox *cb_ptpdla;
        TCheckBox *cb_ptpdle;
        TCheckBox *cb_ptpdra;
        TCheckBox *cb_ptpdr;
        TCheckBox *cb_ptpdre;
        TCheckBox *cb_ptpdlf;
        TCheckBox *cb_ptpdrf;
        TLabel *Label148;
        TLabel *Label150;
        TCurrencyEdit *ed_height;
        TStaticText *et_heightcomm;
        TSpeedButton *bt_seth;
        TSpeedButton *bt_geth;
        TLabel *Label151;
        TCurrencyEdit *ed_airspeed;
        TStaticText *et_airspeed;
        TSpeedButton *bt_setu;
        TSpeedButton *bt_getu;
        TLabel *Label152;
        TCurrencyEdit *ed_r;
        TStaticText *et_rcommand;
        TSpeedButton *bt_setr;
        TSpeedButton *bt_getr;
        TLabel *Label153;
        TCurrencyEdit *ed_gotowp;
        TStaticText *et_gotowp;
        TSpeedButton *SpeedButton19;
        TSpeedButton *SpeedButton20;
        TSpeedButton *bt_ptpil;
        TPanel *Panel3;
        TTabSheet *ts_none;
        TSpeedButton *SpeedButton2;
        TCheckBox *cb_repptpdt;
        TCheckBox *cb_repptpdla;
        TCheckBox *cb_repptpdra;
        TCheckBox *cb_repptpdr;
        TCheckBox *cb_repptpdle;
        TCheckBox *cb_repptpdre;
        TCheckBox *cb_repptpdlf;
        TCheckBox *cb_repptpdrf;
    TCheckBox *CheckBox1;
    TCheckBox *cb_over;
        TLabel *Label149;
        TSpeedButton *SpeedButton5;
        TEdit *ed_gs_file;
        TGroupBox *GroupBox15;
        TLabel *Label68;
        TLabel *Label79;
        TLabel *Label80;
        TLabel *Label81;
        TLabel *Label82;
        TLabel *Label83;
        TLabel *Label84;
        TLabel *Label85;
        TLabel *Label86;
        TStaticText *et_dtc;
        TStaticText *et_dlac;
        TStaticText *et_drac;
        TStaticText *et_drec;
        TStaticText *et_dlfc;
        TStaticText *et_drfc;
        TStaticText *et_drc;
        TStaticText *et_a1c;
        TStaticText *et_dlec;
        TSpeedButton *bt_setallpid;
        TSpeedButton *bt_setallcommands;
        TSpeedButton *bt_getallcommands;
    TSpeedButton *bt_allgains;
        TLabel *Label154;
        TStaticText *et_baro;
        TLabel *Label155;
        TStaticText *et_pitot;
        TLabel *Label156;
        TStaticText *et_therm;
        TLabel *Label157;
        TStaticText *et_power;
    TWSocket *skt_rcv;
    TStaticText *et_height_cmds;
    TStaticText *et_airspeed_cmds;
    TStaticText *et_turnrate_cmds;
        TGroupBox *GroupBox16;
        TLabel *Label158;
        TCurrencyEdit *ed_minh;
        TLabel *Label159;
        TLabel *Label160;
        TCurrencyEdit *ed_maxh;
        TLabel *Label161;
        TCurrencyEdit *ed_minairspeed;
        TCurrencyEdit *ed_maxairspeed;
        TLabel *Label162;
        TCurrencyEdit *ed_minturnrate;
        TCurrencyEdit *ed_maxturnrate;
        TLabel *Label163;
        TLabel *Label164;
        TLabel *Label165;
        TColorComboBox *cb_com;
        TLabel *Label166;
        TLabel *Label167;
        TColorComboBox *cb_mea;
        TRxSlider *RxSlider1;
        TLabel *Label168;
    TTabSheet *TabSheet2;
    TLabel *Label169;
    TAbMiniTrend *mt_a;
    TGroupBox *GroupBox17;
    TLabel *Label170;
    TLabel *Label171;
    TLabel *Label172;
    TLabel *Label174;
    TLabel *Label175;
    TLabel *Label176;
    TLabel *Label177;
        TCurrencyEdit *ed_rollmin;
        TCurrencyEdit *ed_rollmax;
        TCurrencyEdit *ed_rmin;
        TCurrencyEdit *ed_rmax;
        TColorComboBox *cb_lat_1;
        TColorComboBox *cb_lat_2;
    TRxSlider *RxSlider2;
    TLabel *Label178;
    TAbMiniTrend *mt_b;
        TGroupBox *GroupBox18;
        TLabel *Label173;
        TLabel *Label179;
        TLabel *Label180;
        TLabel *Label181;
        TLabel *Label182;
        TLabel *Label183;
        TLabel *Label184;
        TLabel *Label186;
        TStaticText *et_um;
        TStaticText *et_pitchc;
        TStaticText *et_psidc;
        TStaticText *et_towp;
        TStaticText *et_totrun;
        TStaticText *et_dist2go;
        TStaticText *et_phic;
        TStaticText *et_fromwp;
        TLabel *et_lblrhp;
        TStaticText *et_rhp;
        TLabel *Label87;
        TStaticText *et_a2c;
    TTabSheet *ts_navigation;
    TGroupBox *gb_pid6;
    TLabel *Label103;
    TLabel *Label104;
    TLabel *Label105;
    TSpeedButton *bt_up6;
    TSpeedButton *bt_down6;
    TCurrencyEdit *ed_p6;
    TCurrencyEdit *ed_i6;
    TCurrencyEdit *ed_d6;
    TStaticText *et_p6;
    TStaticText *et_i6;
    TStaticText *et_d6;
    TGroupBox *gb_pid7;
    TLabel *Label106;
    TLabel *Label107;
    TLabel *Label108;
    TSpeedButton *bt_up7;
    TSpeedButton *bt_down7;
    TCurrencyEdit *ed_p7;
    TCurrencyEdit *ed_i7;
    TCurrencyEdit *ed_d7;
    TStaticText *et_p7;
    TStaticText *et_i7;
    TStaticText *et_d7;
    TBevel *Bevel1;
    TGroupBox *gb_pid8;
    TLabel *Label109;
    TLabel *Label110;
    TLabel *Label111;
    TSpeedButton *bt_up8;
    TSpeedButton *bt_down8;
    TCurrencyEdit *ed_p8;
    TCurrencyEdit *ed_i8;
    TCurrencyEdit *ed_d8;
    TStaticText *et_p8;
    TStaticText *et_i8;
    TStaticText *et_d8;
    TGroupBox *gb_pid9;
    TLabel *Label113;
    TLabel *Label114;
    TSpeedButton *bt_up9;
    TSpeedButton *bt_down9;
    TCurrencyEdit *ed_i9;
    TCurrencyEdit *ed_d9;
    TStaticText *et_i9;
    TStaticText *et_d9;
    TGroupBox *gb_dtff;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton4;
    TLabel *Label112;
    TCurrencyEdit *ed_p9;
    TStaticText *et_p9;
    TBevel *Bevel2;
        TGroupBox *GroupBox19;
        TLabel *Label187;
        TLabel *Label188;
        TLabel *Label189;
        TLabel *Label193;
        TLabel *Label194;
        TLabel *Label195;
        TStaticText *et_axm;
        TStaticText *et_aym;
        TStaticText *et_azm;
        TStaticText *et_mxm;
        TStaticText *et_mym;
        TStaticText *et_mzm;
        TLabel *Label34;
        TLabel *Label35;
        TLabel *Label36;
        TStaticText *et_phi;
        TStaticText *et_theta;
        TStaticText *et_psi;
        TLabel *Label37;
        TStaticText *et_p;
        TLabel *Label38;
        TLabel *Label39;
        TStaticText *et_q;
        TStaticText *et_r;
    TCheckBox *cb_rhp;
        TGroupBox *GroupBox20;
        TLabel *Label190;
        TLabel *Label191;
        TLabel *Label192;
        TLabel *Label196;
        TLabel *Label197;
        TLabel *Label198;
        TStaticText *et_log1;
        TStaticText *et_log2;
        TStaticText *et_log3;
        TStaticText *et_log4;
        TStaticText *et_log5;
        TStaticText *et_log6;
        void __fastcall FormShow(TObject *Sender);
    void __fastcall bt_clearClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall bt_ppKmlClick(TObject *Sender);
    void __fastcall bt_gearthClick(TObject *Sender);
    void __fastcall cb_color1Exit(TObject *Sender);
    void __fastcall cb_color2Exit(TObject *Sender);
    void __fastcall kb_tessalateExit(TObject *Sender);
    void __fastcall bt_serialClick(TObject *Sender);
    void __fastcall Timer2Timer(TObject *Sender);
    void __fastcall cp_serialTriggerAvail(TObject *CP, WORD Count);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall rg_tailExit(TObject *Sender);
    void __fastcall bt_gsposClick(TObject *Sender);
    void __fastcall bt_filterClick(TObject *Sender);
    void __fastcall bt_onflightexpClick(TObject *Sender);
    void __fastcall ed_exportAfterDialog(TObject *Sender, AnsiString &Name,
          bool &Action);
    void __fastcall cb_inflightClick(TObject *Sender);
    void __fastcall bt_importLogClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall ed_liveLogAfterDialog(TObject *Sender,
          AnsiString &Name, bool &Action);
    void __fastcall skt_rcvSessionClosed(TObject *Sender, WORD ErrCode);
    void __fastcall skt_rcvSessionConnected(TObject *Sender, WORD ErrCode);
    void __fastcall skt_rcvDataAvailable(TObject *Sender, WORD ErrCode);
    void __fastcall StartButtonClick(TObject *Sender);
    void __fastcall StopButtonClick(TObject *Sender);
    void __fastcall bt_startSendClick(TObject *Sender);
    void __fastcall bt_stopSendClick(TObject *Sender);
    void __fastcall AnyServerCheckBoxClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall et_warningDblClick(TObject *Sender);
        void __fastcall bt_up1Click(TObject *Sender);
        void __fastcall ed_p1Change(TObject *Sender);
        void __fastcall bt_down1Click(TObject *Sender);
    void __fastcall bt_allpidClick(TObject *Sender);
    void __fastcall Timer3Timer(TObject *Sender);
        void __fastcall SpeedButton33Click(TObject *Sender);
        void __fastcall bt_allwpClick(TObject *Sender);
        void __fastcall bt_setwp1Click(TObject *Sender);
        void __fastcall bt_getwp1Click(TObject *Sender);
        void __fastcall ed_lat1Change(TObject *Sender);
        void __fastcall bt_sendwpsClick(TObject *Sender);
        void __fastcall cb_stat1Click(TObject *Sender);
        void __fastcall rb_manualClick(TObject *Sender);
        void __fastcall rg_modesClick(TObject *Sender);
        void __fastcall bt_modeClick(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall bt_sethClick(TObject *Sender);
        void __fastcall ed_heightChange(TObject *Sender);
        void __fastcall bt_gethClick(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall bt_setallpidClick(TObject *Sender);
        void __fastcall bt_setallcommandsClick(TObject *Sender);
        void __fastcall bt_getallcommandsClick(TObject *Sender);
        void __fastcall bt_allgainsClick(TObject *Sender);
        void __fastcall ed_minhExit(TObject *Sender);
        void __fastcall ed_maxhExit(TObject *Sender);
        void __fastcall ed_minairspeedChange(TObject *Sender);
        void __fastcall ed_maxairspeedExit(TObject *Sender);
        void __fastcall ed_minturnrateExit(TObject *Sender);
        void __fastcall ed_maxturnrateExit(TObject *Sender);
        void __fastcall cb_comExit(TObject *Sender);
        void __fastcall cb_meaExit(TObject *Sender);
        void __fastcall RxSlider1Changed(TObject *Sender);
        void __fastcall ed_rollminExit(TObject *Sender);
        void __fastcall ed_rminExit(TObject *Sender);
        void __fastcall ed_rollmaxExit(TObject *Sender);
        void __fastcall ed_rmaxExit(TObject *Sender);
        void __fastcall RxSlider2Changed(TObject *Sender);
        void __fastcall cb_lat_1Exit(TObject *Sender);
        void __fastcall cb_lat_2Exit(TObject *Sender);
    void __fastcall ed_p9Change(TObject *Sender);
        void __fastcall cb_rhpClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFPpal(TComponent* Owner);
        void createBlankKML(char KMLType);
        void updateKML(void);
        void addAndAppendNode(char* name, char* value, TiXmlNode* appendTo);
        String getHexColor(unsigned char whichColor);
        String getPlaneCoordinates(void);
        void assembleMsg(unsigned char* rawData , unsigned char size, unsigned char type, unsigned char* protMsg );

        tGpsData                  gpsSamples[15];
        tRawData                  rawSample;
        tAttitudeData             attitudeSample;
        tXYZData                  xyzSample;
        tDynTempData              dynSample;
        tBiasData                 biasSample;
        tDiagData                 diagSample;
        tSensStatus	          statusSample;
        tPilotData	          pilControlSample;
        tAknData                  aknSample;
        tPWMData                  pwmSample;
        tPIDData                  pidSample;
        tWPData                   wpsSample;
        tAPStatusData             apsSample;
        tCommandsData             comSample;
        tNavData                  navSample;
        tSensData                 senSample;
        tLogFloats                logSample;

        String str_modes[10];

        float csFail;

        FILE* liveLog;
        bool logIsOpen;
        bool waitingDelay;
        unsigned char pidRequestQueue;
        unsigned char allGains;

        void updateAkn(void);
        void updateGPSLabels(void);
        void updateRawLabels(void);
        void updateAttitudeLabels(void);
        void updatePlots(void);
        void updateAttitude(void);
        void updatePilotLabels(void);
        void updatePWM(void);
        void updatePID(void);
        void updateWP(void);
        void updateStatus(void);
        bool myisnan(float var);

        void updateBiasLabels(void);
        void updateDynLabels(void);
        void updateDiagLabels(void);

        void updateNav(void);

        void printFileHeader(FILE* fileLog);

        float computeDistance(float lat, float lon);
        float deg2Rad(float mDeg);

        char compare_float(float f1, float f2);


        // HIL
        Winsock::TInAddr      FServerAddr;
        void processUdpMsg(unsigned char * buffer);
        void TxPWMMsg (void);

        // Object Arrays
        // =============

        // PID
        TCurrencyEdit*   PGains [10];
        TCurrencyEdit*   IGains [10];
        TCurrencyEdit*   DGains [10];
        TStaticText*     EtPGains [10];
        TStaticText*     EtIGains [10];
        TStaticText*     EtDGains [10];
        TGroupBox*       BoxCont[10];

        // WayPoints
        TCurrencyEdit*   latVals [10];
        TCurrencyEdit*   lonVals [10];
        TCurrencyEdit*   heiVals [10];
        TCurrencyEdit*   valVals [10];
        TStaticText*     etLatVals [10];
        TStaticText*     etLonVals [10];
        TStaticText*     etHeiVals [10];
        TGroupBox*       boxWP[10];
        TCheckBox*       cbStat[10];
        TCheckBox*       cbRepStat[10];
        TStaticText*     etValVals [10];

//        CircBuffer mainSerial;
//        CBRef telemPort;
};
//---------------------------------------------------------------------------
extern PACKAGE TFPpal *FPpal;
//---------------------------------------------------------------------------
#endif
