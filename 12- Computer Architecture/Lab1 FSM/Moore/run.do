vlib work

vcom *.vhd

vsim -voptargs=+acc work.Moore_FSM_tb.vhd

do wave.do

run -all