

proc EXTN_PTZ_NTX_test { } {

  global mom_out_angle_pos
  global mom_B_coordinate
  global mom_my_tool_type
  global mom_fixture_offset_value
  global mom_kin_4th_axis_vector
  global mom_pos
  global mom_mcs_pos
  global mom_angle_tool_new
  global mom_input_zero_int
  global mom_barfeed_length

  MOM_output_literal "--1--"
  EXTN_PTZ_NTX 1

  MOM_output_literal "--2--"
  MOM_output_literal " $mom_out_angle_pos(0) "
  EXTN_PTZ_NTX 2

  MOM_output_literal "--3--"
  MOM_output_literal " $mom_B_coordinate "
  EXTN_PTZ_NTX 3

  MOM_output_literal "--4--"
  MOM_output_literal " $mom_B_coordinate $mom_my_tool_type"
  EXTN_PTZ_NTX 4

  MOM_output_literal "--5--"
  EXTN_PTZ_NTX 5
  MOM_output_literal "--6--"
  EXTN_PTZ_NTX 6
  MOM_output_literal "--7--"
  EXTN_PTZ_NTX 7
  MOM_output_literal "--8--"
  EXTN_PTZ_NTX 8
  MOM_output_literal "--9--"
  EXTN_PTZ_NTX 9
  MOM_output_literal "--10--"
  EXTN_PTZ_NTX 10
  MOM_output_literal "--11--"
  EXTN_PTZ_NTX 11
  MOM_output_literal "--12--"
  EXTN_PTZ_NTX 12
  MOM_output_literal "--14--"
  EXTN_PTZ_NTX 14

  MOM_output_literal "--15--"
  MOM_output_literal " $mom_fixture_offset_value "
  EXTN_PTZ_NTX 15

  MOM_output_literal "--16--"
  MOM_output_literal " $mom_kin_4th_axis_vector(0) $mom_kin_4th_axis_vector(1) $mom_kin_4th_axis_vector(2)"
  EXTN_PTZ_NTX 16
  MOM_output_literal " $mom_kin_4th_axis_vector(0) $mom_kin_4th_axis_vector(1) $mom_kin_4th_axis_vector(2)"

  MOM_output_literal "--18--"
  MOM_output_literal " $mom_input_zero_int "
  EXTN_PTZ_NTX 18

  MOM_output_literal "--20--"
  MOM_output_literal " $mom_pos(0) $mom_pos(1) $mom_pos(2)"
  EXTN_PTZ_NTX 20

  MOM_output_literal "--34--"
  MOM_output_literal " $mom_out_angle_pos(0)  $mom_out_angle_pos(1) "
  EXTN_PTZ_NTX 34

  MOM_output_literal "--111--"
  MOM_output_literal " $mom_out_angle_pos(0)  $mom_out_angle_pos(1) "
  EXTN_PTZ_NTX 111

  MOM_output_literal "--112--"
  MOM_output_literal " $mom_out_angle_pos(0)  $mom_out_angle_pos(1) "
  EXTN_PTZ_NTX 112

  MOM_output_literal "--114--"
  EXTN_PTZ_NTX 114

  MOM_output_literal "--128--"
  MOM_output_literal " $mom_pos(0) $mom_pos(1) $mom_pos(2)"
  MOM_output_literal " $mom_mcs_goto(0) $mom_mcs_goto(1) $mom_mcs_goto(2)"
  EXTN_PTZ_NTX 128
  MOM_output_literal " $mom_pos(0) $mom_pos(1) $mom_pos(2)"

  MOM_output_literal "--130--"
  EXTN_PTZ_NTX 130

  MOM_output_literal "--131--"
  EXTN_PTZ_NTX 131

  MOM_output_literal "--132--"
  EXTN_PTZ_NTX 132

  MOM_output_literal "--133--"
  EXTN_PTZ_NTX 133

  MOM_output_literal "--134--"
  EXTN_PTZ_NTX 134

  MOM_output_literal "--135--"
  EXTN_PTZ_NTX 135

  MOM_output_literal "--136--"
  MOM_output_literal " $mom_fixture_offset_value "
  EXTN_PTZ_NTX 136

  MOM_output_literal "--137--"
  MOM_output_literal " $mom_fixture_offset_value $mom_barfeed_length"
  EXTN_PTZ_NTX 137

  MOM_output_literal "--138--"
  MOM_output_literal " $mom_fixture_offset_value "
  EXTN_PTZ_NTX 138

  MOM_output_literal "--139--"
  MOM_output_literal " $mom_fixture_offset_value "
  EXTN_PTZ_NTX 139

  MOM_output_literal "--140--"
  EXTN_PTZ_NTX 140

  return
}

