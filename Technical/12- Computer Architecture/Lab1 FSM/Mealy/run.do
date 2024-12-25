vlib work

vcom *.vhd

vsim -voptargs=+acc work.Mealy_FSM_tb.vhd

do wave.do

run -all