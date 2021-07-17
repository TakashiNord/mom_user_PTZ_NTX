//////////////////////////////////////////////////////////////////////////////
//
//  mom_user.cpp
//
//  Description:
//      Contains Unigraphics entry points for the application.
//
//////////////////////////////////////////////////////////////////////////////

// #define _CRT_SECURE_NO_DEPRECATE 1

//  Include files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <uf.h>
#include <uf_exit.h>
#include <uf_ui.h>
#include <uf_mom.h>

#include <uf_vec.h>
#include <uf_obj.h>

#include "mom_user.h"

//----------------------------------------------------------------------------

/*
 * Exported Tcl procedures:
 */
static int sub_program
(
  void *client_data,    /* This is the mom object */
  void *interp,         /* Pointer to the TCL interpreter */
  int  argc,            /* Count of the numnber of arguments */
  char **argv           /* Array of arguments where the
                           argv[0] - The TCL extension */
);

//----------------------------------------------------------------------------
//  Activation Methods
//----------------------------------------------------------------------------

//  Explicit Activation
//      This entry point is used to activate the application explicitly, as in
//      "File->Execute UG/Open->User Function..."
//----------------------------------------------------------------------------
extern "C" DllExport void entry_PTZ_NTX( char *parm, int *returnCode, int rlen )
{
  int errorCode ;
  UF_MOM_id_t mom ;
  void *interp = NULL ;

  if ( !UF_is_initialized() )
  {
    errorCode = UF_initialize();
    *returnCode = errorCode;
  }

  /* Get the TCL interpreter id from the ufusr param */
  // UF_MOM_ask_interp_from_param ( parm, &interp ) ;
  /* Get the MOM id from the ufusr param */
  UF_MOM_ask_mom (parm, &mom) ;

  UF_MOM_extend_xlator ( mom , "EXTN_PTZ_NTX", sub_program ) ;

  errorCode = UF_terminate();
  *returnCode = errorCode;
}


//----------------------------------------------------------------------------
//  Utilities
//----------------------------------------------------------------------------

// Unload Handler
//     This function specifies when to unload your application from Unigraphics.
//     If your application registers a callback (from a MenuScript item or a
//     User Defined Object for example), this function MUST return
//     "UF_UNLOAD_UG_TERMINATE".
extern "C" int ufusr_ask_unload( void )
{
     /* unload immediately after application exits*/
     //return ( UF_UNLOAD_IMMEDIATELY );

     /*via the unload selection dialog... */
     return ( UF_UNLOAD_SEL_DIALOG );
     /*when UG terminates...              */
     //return ( UF_UNLOAD_UG_TERMINATE );
}


/*-----------------------------------------------------------------------
 * Function Name: sub_program
 *
 *
 -----------------------------------------------------------------------*/
static int sub_program
(
  void *client_data,    /* This is the mom object */
  void *interp,         /* Pointer to the TCL interpreter */
  int  argc,            /* Count of the numnber of arguments */
  char **argv           /* Array of arguments where the
                           argv[0] - The TCL extension */
)
{
  UF_MOM_id_t mom_id = ( UF_MOM_id_t ) client_data ;

  char    Dest[256] ;
  double  angle1 , angle2 ;
  int     ii ;
  int     case_id ;
  double  x , y , z , i , j , k ;
  const char *String , *String2, *String3, *String4 ;

  /*
  printf("Number of args %ld ", argc);
  for ( ii = 0; ii < argc; ++ii )
    printf(" %s", argv[ii]);
    */

  case_id=atoi(argv[1]);

  switch ( case_id )
  {
    case 1:
      UF_MOM_execute_command(mom_id, "PB_CMD_output_spindle");
      break ;
    case 2:
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "0", &angle1);
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "1", &angle2);
      angle1=angle1+90.0 ;
      sprintf(Dest, "MOM_output_literal \"G68.1 X0 Y0 Z0 I0 J1 K0 R%.3lf\"", angle1);
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 3:
      UF_MOM_ask_string(mom_id, "B_coordinate", &String);
      x = atof(String);
      sprintf(Dest, "MOM_output_literal \"G361 B%.3lf D0\"", x);
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 4:
      UF_MOM_ask_string(mom_id, "B_coordinate", &String);
      UF_MOM_ask_string(mom_id, "my_tool_type", &String2);
      x = atof(String2);
      y = atof(String);
      sprintf(Dest, "MOM_output_literal \"G361 B%.3lf D%.0lf\"", y, x);
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 5:
      sprintf(Dest, "MOM_output_literal \"G49\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G05.1 Q1\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G43.4 D9\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 6:
      sprintf(Dest, "MOM_output_literal \"G49\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G69.1\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 7:
      sprintf(Dest, "MOM_output_literal \"G49\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G05.1 Q0\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"M368\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"M595\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 8:
      sprintf(Dest, "MOM_output_literal \"G00 G28 U0.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 9:
      sprintf(Dest, "MOM_output_literal \"G00 G28 W0.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 10:
      sprintf(Dest, "MOM_output_literal \"G00 G28 V0.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 11:
      sprintf(Dest, "PB_CMD_output_spindle_TURN");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 12:
      sprintf(Dest, "PB_CMD_output_spindle_MILL");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 14:
      sprintf(Dest, "PB_CMD_format_value");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 15:
      UF_MOM_ask_string(mom_id, "fixture_offset_value", &String2);
      x = atof(String2);
      sprintf(Dest, "MOM_output_literal \"M49 ;(Razzhim kulachkov kontrspindelja)\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \";(Zikl otvoda kontrspindelja bez zagotovki)\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest,"MOM_output_literal \"F_SUB_SP(1000101103,,,,,,90,,,%.3lf,,0,610,250,590,,2,,0,0,0)\"", x);
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"M48 ;(Zazhim kulachkov kontrspindelja)\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 16:
      UF_MOM_ask_assoc_double_array(mom_id, "kin_4th_axis_vector", "0", &i);
      UF_MOM_ask_assoc_double_array(mom_id, "kin_4th_axis_vector", "1", &j);
      UF_MOM_ask_assoc_double_array(mom_id, "kin_4th_axis_vector", "2", &k);
      i = 0;
      j =+1; // 4607182418800017408i64;
      k = 0;
      UF_MOM_set_assoc_double_array(mom_id, "kin_4th_axis_vector", "0",i);
      UF_MOM_set_assoc_double_array(mom_id, "kin_4th_axis_vector", "1",j);
      UF_MOM_set_assoc_double_array(mom_id, "kin_4th_axis_vector", "2",k);
      break;
    case 18:
      UF_MOM_ask_string(mom_id, "angle_tool_new", &String3);
      UF_MOM_ask_string(mom_id, "input_zero_int", &String4);
      x = atof(String3);
      sprintf(Dest, "MOM_output_literal \"G0 B%.3lf\"", x);
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"M107\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 20:
      UF_MOM_ask_assoc_double_array(mom_id, "pos", "0", &x);
      UF_MOM_ask_assoc_double_array(mom_id, "pos", "1", &y);
      UF_MOM_ask_assoc_double_array(mom_id, "pos", "2", &z);
      sprintf(Dest, "MOM_output_literal \"G0 G90 X%.3lf Y%.3lf Z%.3lf\"", x,y,z);
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 34:
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "0", &angle1);
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "1", &angle2);
      sprintf(Dest, "MOM_output_literal \"AROT X%.3lf Y%.3lf\"", angle1, angle2);
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 111:
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "0", &angle1);
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "1", &angle2);
      x = angle1 * (-1.0);
      angle1 = angle1 * (-1.0);
      angle2 = angle2 * (-1.0);
      sprintf(Dest, "MOM_output_literal \"AROT X%.3lf Z%.3lf\"", x, angle2);
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 112:
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "0", &angle1);
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "1", &angle2);
      x = angle1;
      angle2 = angle2 * (-1.0);
      sprintf(Dest, "MOM_output_literal \"AROT X%.3lf Z%.3lf\"", x, angle2);
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 114:
      sprintf(Dest, "MOM_output_literal \"ROT Y90\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 128:
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "0", &x);
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "1", &y);
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "2", &z);
      UF_MOM_set_assoc_double_array(mom_id, "pos", "0",x);
      UF_MOM_set_assoc_double_array(mom_id, "pos", "1",y);
      UF_MOM_set_assoc_double_array(mom_id, "pos", "2",z);
      break;
    case 130:
      sprintf(Dest, "MOM_output_literal \"G0 G90 G53 D0 X280.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G0 G90 G53 Z270.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 131:
      sprintf(Dest, "MOM_output_literal \"G0 G90 G53 D0 X280.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G0 G90 G53 Z550.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"SPOS\\1332\\135=0\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 132:
      sprintf(Dest, "MOM_output_literal \"G00 G90 G53 D0 X2=280.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G00 G90 G53 Z2=270.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"SPOS\\1332\\135=0\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 133:
      sprintf(Dest, "MOM_output_literal \"G00 G90 G53 D0 X370.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G00 G90 G53 Y-90.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G00 G90 G53 Z700.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G00 G90 G53 B90.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 134:
      sprintf(Dest, "MOM_output_literal \"G00 G90 G53 D0 Z500.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 135:
      sprintf(Dest, "MOM_output_literal \"G00 G90 G53 D0 Z800.0\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 136:
      UF_MOM_ask_string(mom_id, "fixture_offset_value", &String2);
      x = atof(String2);
      sprintf(Dest, "MOM_output_literal \";(Razzhim kulachkov kontrspindelja)\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"M2=25\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \";(Zikl otvoda kontrspindelja bez zagotovki)\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest,"MOM_output_literal \"F_SUB_SP(1000101103,,,,,,90,,,%.3lf,,0,1300,375,250,,2,,0,0,0)\"", x);
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \";(Zazhim kulachkov kontrspindelja)\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"M2=26\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 137:
      UF_MOM_ask_string(mom_id, "fixture_offset_value", &String2);
      ii = (int)floor(atof(String2));
      UF_MOM_ask_string(mom_id, "barfeed_length", &String3);
      x = atof(String3);
      sprintf(Dest, "MOM_output_literal \"NULL_POINT_Z3 = \\044P_UIFR\\133%d,Z3,TR\\135\"", ii);
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"NULL_POINT_Z3 = NULL_POINT_Z3 + %.3lf\"", x);
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"\\044P_UIFR\\133%d,Z3,TR\\135 = NULL_POINT_Z3\"", ii);
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 138:
      UF_MOM_ask_string(mom_id, "fixture_offset_value", &String2);
      ii = (int)floor(atof(String2));
      sprintf(Dest,"MOM_output_literal \"NULL_POINT_Z = \\044P_UIFR\\133%d,Z,TR\\135\"", ii);
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest,"MOM_output_literal \"NULL_POINT_Z3 = \\044P_UIFR\\133%d,Z3,TR\\135\"", ii);
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 139:
      UF_MOM_ask_string(mom_id, "fixture_offset_value", &String2);
      x = atof(String2);
      sprintf(Dest, "MOM_output_literal \";(Razzhim kulachkov kontrspindelja)\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"M2=25\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \";(Zikl otvoda kontrspindelja bez zagotovki)\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"F_SUB_SP(1000101103,,,,,,90,,,%.3lf,,0,1300,375,55,,2,,0,0,0)\"", x);
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \";(Zazhim kulachkov kontrspindelja)\"");
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"M2=26\"");
      UF_MOM_execute_command(mom_id, Dest);
      break ;
    case 140:
      sprintf(Dest, "MOM_output_literal \"SETMS(2)\"");
      UF_MOM_execute_command(mom_id, Dest);
      break;
    default:
      break;
  }

  //UF_MOM_set_string(mom_id, "entry_PTZ_NTX", Dest);
  //UF_terminate();

  return ( 0 ) ;
}

