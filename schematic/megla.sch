<Qucs Schematic 0.0.18>
<Properties>
  <View=0,-58,800,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=megla.dat>
  <DataDisplay=megla.dpl>
  <OpenDisplay=1>
  <Script=megla.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
  <.PortSym 40 20 1 0>
</Symbol>
<Components>
  <GND * 1 290 260 0 0 0 0>
  <Diode D1 1 180 200 -26 -27 0 2 "1e-15 A" 0 "1" 0 "10 fF" 0 "0.5" 0 "0.7 V" 0 "0.5" 0 "0.0 fF" 0 "0.0" 0 "2.0" 0 "0.0 Ohm" 0 "0.0 ps" 0 "0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0" 0 "1 mA" 0 "26.85" 0 "3.0" 0 "1.11" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "26.85" 0 "1.0" 0 "normal" 0>
  <R R1 1 120 80 -45 -54 0 0 "1 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R2 1 120 200 -26 15 0 0 "4.7 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <_BJT TIP42C_1 1 210 80 3 -74 1 1 "pnp" 1 "5.65618e-10" 0 "1.24004" 0 "1.30331" 0 "1.46498" 0 "10" 0 "90.6071" 0 "27.1221" 0 "6.9828e-14" 0 "4" 0 "6.98934e-14" 0 "3.78125" 0 "50" 1 "2.83268" 0 "0.12691" 0 "0.234602" 0 "0.0927424" 0 "0.000666374" 0 "4.71382" 0 "01.93221e-10" 0 "0.4" 0 "0.259369" 0 "1.0962e-10" 0 "0.731968" 0 "0.23" 0 "0.799902" 0 "0" 0 "0.75" 0 "0.5" 0 "0.799995" 0 "9.99163e-9" 0 "4.41941" 0 "6.53488" 0 "0.001" 0 "1e-7" 0 "26.85" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "1.0" 0 "1.0" 0 "0.0" 0 "0.0" 0 "3.0" 0 "1.11" 0 "26.85" 0 "1.0" 0>
  <Lib LM7805 1 290 200 -40 -46 0 0 "Regulators" 0 "LM140-5V" 0>
  <C C1 1 360 230 17 -26 0 1 "100 nF" 1 "" 0 "neutral" 0>
  <R R3 1 180 110 -78 10 0 1 "28 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 20 140 0 0 0 0>
  <Vdc V1 1 20 110 18 -26 0 1 "24 V" 1>
  <C C2 1 210 230 -53 40 0 1 "1 uF" 1 "" 0 "neutral" 0>
  <Lib D2 1 120 340 10 -29 0 2 "LEDs" 0 "green" 0>
  <R R4 1 180 340 -26 15 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 210 340 0 0 0 0>
  <Port P_indicator 1 40 340 -23 12 0 0 "1" 1 "analog" 0>
</Components>
<Wires>
  <210 260 290 260 "" 0 0 0 "">
  <150 80 180 80 "" 0 0 0 "">
  <210 110 210 140 "" 0 0 0 "">
  <210 200 240 200 "" 0 0 0 "">
  <290 230 290 260 "" 0 0 0 "">
  <240 80 360 80 "" 0 0 0 "">
  <340 200 360 200 "" 0 0 0 "">
  <290 260 360 260 "" 0 0 0 "">
  <360 80 360 200 "" 0 0 0 "">
  <210 140 210 200 "" 0 0 0 "">
  <180 140 210 140 "" 0 0 0 "">
  <90 80 90 200 "" 0 0 0 "">
  <20 80 90 80 "" 0 0 0 "">
  <40 340 90 340 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>