# **Description:** 
The Advanced Peripheral Bus (APB) is a simplified interface used for connecting peripherals to a 
system in embedded systems, particularly in SoCs (System-on-Chip). It is designed for low-bandwidth, 
low-latency communication, making it ideal for simpler, slower peripherals such as timers, UARTs, and 
GPIOs. The APB protocol consists of basic handshaking signals and provides simple, single-cycle access 
to devices. 

![image](assets/APB.jpg)

The APB bus uses the following primary signals: 
• PADDR: Address bus. 
• PWDATA: Write data bus. 
• PRDATA: Read data bus. 
• PSEL: Select signal, used to identify which peripheral is being accessed. 
• PWRITE: Write control signal (indicates write operation). 
• PENABLE: Enables the transfer cycle. 
• PREADY: Slave ready signal, indicating the completion of the operation. 

# **Finite State Machines**

1.	Master Interface

![image](assets/Master_FSM.png)

2.	Slave Interface

![image](assets/Slave_FSM.png)


# **ABP Protocol Design on Falstad**

![image](assets/APB%20Protocol.png)