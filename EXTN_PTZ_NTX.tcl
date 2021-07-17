

proc EXTN_PTZ_NTX { mode } {

  switch $mode {
     1 {
      PB_CMD_output_spindle
      }
     2 {
      global mom_out_angle_pos
      set ang1 [ expr $mom_out_angle_pos(0)+90.0 ]
      set fmt "G68.1 X0 Y0 Z0 I0 J1 K0 R%.3lf"
      set str [format $fmt $ang1 ]
      MOM_output_literal $str
      }
     3 {
      global mom_B_coordinate
      set fmt "G361 B%.3lf D0"
      set str [format $fmt $mom_B_coordinate ]
      MOM_output_literal $str
      }
     4 {
      global mom_B_coordinate
      global mom_my_tool_type
      set fmt "G361 B%.3lf D%.0lf"
      set str [format $fmt $mom_B_coordinate $mom_my_tool_type ]
      MOM_output_literal $str
      }
     5 {
      MOM_output_literal "G49"
      MOM_output_literal "G05.1 Q1"
      MOM_output_literal "G43.4 D9"
      }
     6 {
      MOM_output_literal "G49"
      MOM_output_literal "G69.1"
      }
     7 {
      MOM_output_literal "G49"
      MOM_output_literal "G05.1 Q0"
      MOM_output_literal "M368"
      MOM_output_literal "M595"
      }
     8 {
      MOM_output_literal "G00 G28 U0.0"
      }
     9 {
      MOM_output_literal "G00 G28 W0.0"
      }
     10 {
      MOM_output_literal "G00 G28 V0.0"
      }
     11 {
      PB_CMD_output_spindle_TURN
      }
     12 {
      PB_CMD_output_spindle_MILL
      }
     14 {
      PB_CMD_format_value
      }
     15 {
      global mom_fixture_offset_value
      MOM_output_literal "M49 ;(Razzhim kulachkov kontrspindelja)"
      MOM_output_literal ";(Zikl otvoda kontrspindelja bez zagotovki)"
      set fmt "F_SUB_SP(1000101103,,,,,,90,,,%.3lf,,0,610,250,590,,2,,0,0,0)"
      set str [format $fmt $mom_fixture_offset_value ]
      MOM_output_literal $str
      MOM_output_literal "M48 ;(Zazhim kulachkov kontrspindelja)"
      }
     16 {
      global mom_kin_4th_axis_vector
      set mom_kin_4th_axis_vector(0) 0.0
      set mom_kin_4th_axis_vector(1) 1.0
      set mom_kin_4th_axis_vector(2) 0.0
      }
     18 {
      global mom_angle_tool_new
      global mom_input_zero_int
      set fmt "G0 B%.3lf"
      set str [format $fmt $mom_angle_tool_new ]
      MOM_output_literal $str
      MOM_output_literal "M107"
      }
     20 {
      global mom_pos
      set fmt "G0 G90 X%.3lf Y%.3lf Z%.3lf"
      set str [format $fmt $mom_pos(0) $mom_pos(1) $mom_pos(2) ]
      MOM_output_literal $str
      }
     34 {
      global mom_out_angle_pos
      set fmt "AROT X%.3lf Y%.3lf"
      set str [format $fmt $mom_out_angle_pos(0) $mom_out_angle_pos(1) ]
      MOM_output_literal $str
      }
     111 {
      global mom_out_angle_pos
      set angle1 [ expr $mom_out_angle_pos(0) * (-1.0) ]
      set angle2 [ expr $mom_out_angle_pos(1) * (-1.0) ]
      set fmt "AROT X%.3lf Z%.3lf"
      set str [format $fmt $angle1 $angle2 ]
      MOM_output_literal $str
      }
     112 {
      global mom_out_angle_pos
      set angle1 $mom_out_angle_pos(0)
      set angle2 [ expr $mom_out_angle_pos(1) * (-1.0) ]
      set fmt "AROT X%.3lf Z%.3lf"
      set str [format $fmt $angle1 $angle2 ]
      MOM_output_literal $str
      }
     114 {
      MOM_output_literal "ROT Y90"
      }
     128 {
      global mom_mcs_goto mom_pos
      set mom_pos(0) $mom_mcs_goto(0)
      set mom_pos(1) $mom_mcs_goto(1)
      set mom_pos(2) $mom_mcs_goto(2)
       }
     130 {
      MOM_output_literal "G0 G90 G53 D0 X280.0"
      MOM_output_literal "G0 G90 G53 Z270.0"
      }
     131 {
      MOM_output_literal "G0 G90 G53 D0 X280.0"
      MOM_output_literal "G0 G90 G53 Z550.0"
      MOM_output_literal "SPOS\[2\]=0"
      }
     132 {
      MOM_output_literal "G00 G90 G53 D0 X2=280.0"
      MOM_output_literal "G00 G90 G53 Z2=270.0"
      MOM_output_literal "SPOS\[2\]=0"
      }
     133 {
      MOM_output_literal "G00 G90 G53 D0 X370.0"
      MOM_output_literal "G00 G90 G53 Y-90.0"
      MOM_output_literal "G00 G90 G53 Z700.0"
      MOM_output_literal "G00 G90 G53 B90.0"
      }
     134 {
      MOM_output_literal "G00 G90 G53 D0 Z500.0"
      }
     135 {
      MOM_output_literal "G00 G90 G53 D0 Z800.0"
      }
     136 {
      global mom_fixture_offset_value
      MOM_output_literal ";(Razzhim kulachkov kontrspindelja)"
      MOM_output_literal "M2=25"
      MOM_output_literal ";(Zikl otvoda kontrspindelja bez zagotovki)"

      set fmt "F_SUB_SP(1000101103,,,,,,90,,,%.3lf,,0,1300,375,250,,2,,0,0,0)"
      set str [format $fmt $mom_fixture_offset_value ]
      MOM_output_literal $str

      MOM_output_literal ";(Zazhim kulachkov kontrspindelja)"
      MOM_output_literal "M2=26"
      }
     137 {
      global mom_fixture_offset_value
      global mom_barfeed_length

      set fmt "NULL_POINT_Z3 = \$P_UIFR\[%d,Z3,TR\]"
      set str [format $fmt $mom_fixture_offset_value ]
      MOM_output_literal $str

      set fmt "NULL_POINT_Z3 = NULL_POINT_Z3 + %.3lf"
      set str [format $fmt $mom_barfeed_length ]
      MOM_output_literal $str

      set fmt "\$P_UIFR\[%d,Z3,TR\] = NULL_POINT_Z3"
      set str [format $fmt $mom_fixture_offset_value ]
      MOM_output_literal $str
      }
     138 {
      global mom_fixture_offset_value

      set fmt "NULL_POINT_Z = \$P_UIFR\[%d,Z,TR\]"
      set str [format $fmt $mom_fixture_offset_value ]
      MOM_output_literal $str

      set fmt "NULL_POINT_Z3 = \$P_UIFR\[%d,Z3,TR\]"
      set str [format $fmt $mom_fixture_offset_value ]
      MOM_output_literal $str
      }
     139 {
      global mom_fixture_offset_value
      MOM_output_literal ";(Razzhim kulachkov kontrspindelja)"
      MOM_output_literal "M2=25"
      MOM_output_literal ";(Zikl otvoda kontrspindelja bez zagotovki)"

      set fmt "F_SUB_SP(1000101103,,,,,,90,,,%.3lf,,0,1300,375,55,,2,,0,0,0)"
      set str [format $fmt $mom_fixture_offset_value ]
      MOM_output_literal $str

      MOM_output_literal ";(Zazhim kulachkov kontrspindelja)"
      MOM_output_literal "M2=26"
      }
     140 {
      MOM_output_literal "SETMS(2)"
      }
    default {
        ;
      }
  }

  return
}

