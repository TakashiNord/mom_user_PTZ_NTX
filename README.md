# mom_user_PTZ_NTX
 mom_user for PTZ by NTX

____

The part of the postprocessor for PTZ by NTX.
- 2011? year.
- CAD\CAM\CAE : Unigraphics
- parts postprocessor: tcl, def and dll
- EXTN_PTZ_NTX.tcl - replacing the dll
- EXTN_PTZ_NTX_test.tcl - unit test
- Exporting function dll : EXTN_PTZ_NTX
used
```
EXTN_PTZ_NTX 1 ; # PB_CMD_output_spindle
EXTN_PTZ_NTX 2 ; # G68.1 X0 Y0 Z0 I0 J1 K0 R%.3lf
EXTN_PTZ_NTX 3 ; # G361 B%.3lf D0
EXTN_PTZ_NTX 4 ; # G361 B%.3lf D0
EXTN_PTZ_NTX 5 ; # G49+G05.1 Q1+G43.4 D9
EXTN_PTZ_NTX 6 ; # G49+G69.1
EXTN_PTZ_NTX 7 ; # G49+G05.1 Q1+M368+M595
EXTN_PTZ_NTX 8 ; # G28 U0.0
EXTN_PTZ_NTX 9 ; # G28 W0.0
EXTN_PTZ_NTX 10 ; # G28 V0.0
EXTN_PTZ_NTX 11 ; # PB_CMD_output_spindle_TURN
EXTN_PTZ_NTX 12 ; # PB_CMD_output_spindle_MILL

EXTN_PTZ_NTX 14 ; # PB_CMD_format_value
EXTN_PTZ_NTX 15 ; # fixture_offset_value
EXTN_PTZ_NTX 16 ; # kin_4th_axis_vector

EXTN_PTZ_NTX 18 ; # G0 B%.3lf+M107

EXTN_PTZ_NTX    20 ; # G0 G90 X%.3lf Y%.3lf Z%.3lf

EXTN_PTZ_NTX    34 ; # AROT X%.3lf Y%.3lf

EXTN_PTZ_NTX    111 ; # AROT X%.3lf Z%.3lf
EXTN_PTZ_NTX    112 ; # AROT X%.3lf Z%.3lf

EXTN_PTZ_NTX    114 ; # ROT Y90

EXTN_PTZ_NTX    128 ; # pos=mcs_goto

EXTN_PTZ_NTX    130 ; # G53 D0 X280.0+G53 Z270.0
EXTN_PTZ_NTX    131 ; # G53 D0 X280.0+G53 Z550.0+SPOS
EXTN_PTZ_NTX    132 ; # G53 D0 X2=280.0+G53 Z2=270.0+SPOS
EXTN_PTZ_NTX    133 ; # G53 D0 X370.0+G53 Y-90.0+G53 Z700.0
EXTN_PTZ_NTX    134 ; # G53 D0 Z500.0
EXTN_PTZ_NTX    135 ; # G90 G53 D0 Z800.0
EXTN_PTZ_NTX    136 ; # fixture_offset_value
EXTN_PTZ_NTX    137 ; # fixture_offset_value 2
EXTN_PTZ_NTX    138 ; # fixture_offset_value 3
EXTN_PTZ_NTX    139 ; # fixture_offset_value 4
EXTN_PTZ_NTX    140 ; # SETMS(2)

```

The protection is based on the function:
```
?:
```
____


