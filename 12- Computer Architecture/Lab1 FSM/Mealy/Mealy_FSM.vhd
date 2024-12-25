library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity patternMealy is
    port(
        clk   : in  STD_LOGIC;
        reset : in  STD_LOGIC;
        a     : in  STD_LOGIC;
        y     : out STD_LOGIC
    );
end;

architecture synth of patternMealy is
    type state_type is (S0, S1, S2);
    signal state, next_state : state_type;
begin
    -- State register
    process(clk, reset)
    begin
        if reset = '1' then
            state <= S0;
        elsif rising_edge(clk) then
            state <= next_state;
        end if;
    end process;

    -- Next state logic
    process(state, a)
    begin
        case state is
            when S0 =>
                if a = '1' then
                    next_state <= S0;
                else
                    next_state <= S1;
                end if;
            when S1 =>
                if a = '1' then
                    next_state <= S2;
                else
                    next_state <= S1;
                end if;
            when S2 =>
                if a = '1' then
                    next_state <= S0;
                else
                    next_state <= S1;
                end if;
            when others =>
                next_state <= S0;
        end case;
    end process;

    -- Output logic
    y <= '1' when (a = '1' and state = S2) else '0';

end;