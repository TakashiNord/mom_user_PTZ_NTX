# mom_user_PTZ_NTX
 mom_user for PTZ by NTX

____

The part of the postprocessor for PTZ by NTX.
- 2011? year.
- CAD\CAM\CAE : Unigraphics
- parts postprocessor: tcl, def and dll
- mom_user_Mazak_Integrex_i630V_2017.tcl - replacing the dll
- mom_user_Mazak_Integrex_i630V_2017.tcl - replacing the dll
- Exporting function dll : EXTN_rtv_mom_cp_part_attr
used
```
EXTN_rtv_mom_cp_part_attr PLANE_VORTEX
EXTN_rtv_mom_cp_part_attr G43_MOVE_VORTEX
EXTN_rtv_mom_cp_part_attr G43_MOVE_VORTEX_%
EXTN_rtv_mom_cp_part_attr PLANE
EXTN_rtv_mom_cp_part_attr PLANE_dynamic
EXTN_rtv_mom_cp_part_attr G43_MOVE
EXTN_rtv_mom_cp_part_attr PLANE_MILL2
EXTN_rtv_mom_cp_part_attr PLANE_MILL2_PR
EXTN_rtv_mom_cp_part_attr PLANE2
EXTN_rtv_mom_cp_part_attr PLANE_END
EXTN_rtv_mom_cp_part_attr PLANE_moving
EXTN_rtv_mom_cp_part_attr PLANE_moving2
EXTN_rtv_mom_cp_part_attr Recalc_Pos
EXTN_rtv_mom_cp_part_attr Recalc_Pos_G43
EXTN_rtv_mom_cp_part_attr Recalc_Pos_G43_rap
EXTN_rtv_mom_cp_part_attr INPUT_RETRACT
EXTN_rtv_mom_cp_part_attr INPUT_RETRACT_DIST
EXTN_rtv_mom_cp_part_attr UNLOAD
```

The protection is based on the function:
```
GetVolumeInformation:
```
____



 EXTN_PTZ_NTX {
    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    11
    12
    14
    15
    16
    18
    20
    34
    111
    112
    114
    128
    130
    131
    132
    133
    134
    135
    136
    137
    138
    139
    140
 }
