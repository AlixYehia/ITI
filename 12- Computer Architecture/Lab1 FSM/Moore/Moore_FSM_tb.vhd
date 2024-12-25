library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity patternMoore_tb is
end entity;

architecture simulation of patternMoore_tb is
    constant clk_period : time := 10 ns;
    signal clk_tb : std_logic := '0';
    signal reset_tb : std_logic := '0';
    signal a_tb : std_logic := '0';
    signal y_tb : std_logic;
    signal test_vector : std_logic_vector(14 downto 0) := "010011110001100";
    signal index : integer := 0;

begin

    -- Clock generation process
    clock_gen : process
    begin
        clk_tb <= '0';
        wait for clk_period / 2;
        clk_tb <= '1';
        wait for clk_period / 2;
    end process;

    -- Instantiate the Moore FSM component
    moore_fsm_inst : entity work.patternMoore
    port map (
        clk   => clk_tb,
        reset => reset_tb,
        a     => a_tb,
        y     => y_tb
    );

    -- Stimulus process to apply inputs and reset
    stimulus_proc : process
    begin
        -- Apply reset pulse
        wait until rising_edge(clk_tb);
        reset_tb <= '1';
        wait until rising_edge(clk_tb);
        reset_tb <= '0';

        -- Apply input vector pattern to the FSM
        for index in test_vector'range loop
            a_tb <= test_vector(index);
            wait until rising_edge(clk_tb);
        end loop;
        
        -- End of test
        wait;
    end process;

    monitor_output : process(y_tb)
    begin
        if y_tb = '1' then
            report "Output Y is set to 1 at time " & time'image(now);
        end if;
    end process;

end architecture;


