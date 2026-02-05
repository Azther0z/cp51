module rom (
    input  wire       clk,
    input  wire [3:0] in,
    output wire [7:0] out
);

    // TODO: Fill template of ROM from language template and adjust parameters/ports as needed.
    xpm_memory_sprom #(
        .ADDR_WIDTH_A(4),  // DECIMAL
        .AUTO_SLEEP_TIME(0),  // DECIMAL
        .CASCADE_HEIGHT(0),  // DECIMAL
        .ECC_BIT_RANGE("7:0"),  // String
        .ECC_MODE("no_ecc"),  // String
        .ECC_TYPE("none"),  // String
        .IGNORE_INIT_SYNTH(0),  // DECIMAL
        .MEMORY_INIT_FILE("data.mem"),  // String
        .MEMORY_INIT_PARAM(""),  // String
        .MEMORY_OPTIMIZATION("true"),  // String
        .MEMORY_PRIMITIVE("auto"),  // String
        .MEMORY_SIZE(128),  // DECIMAL
        .MESSAGE_CONTROL(0),  // DECIMAL
        .RAM_DECOMP("auto"),  // String
        .READ_DATA_WIDTH_A(8),  // DECIMAL
        .READ_LATENCY_A(1),  // DECIMAL
        .READ_RESET_VALUE_A("0"),  // String
        .RST_MODE_A("SYNC"),  // String
        .SIM_ASSERT_CHK(0),  // DECIMAL; 0=disable simulation messages, 1=enable simulation messages
        .USE_MEM_INIT(1),  // DECIMAL
        .USE_MEM_INIT_MMI(1),  // DECIMAL
        .WAKEUP_TIME("disable_sleep")  // String
    ) xpm_memory_sprom_inst (
        .dbiterra(),  // 1-bit output: Leave open.
        .douta(out),  // READ_DATA_WIDTH_A-bit output: Data output for port A read operations.
        .sbiterra(),  // 1-bit output: Leave open.
        .addra(in),  // ADDR_WIDTH_A-bit input: Address for port A read operations.
        .clka(clk),  // 1-bit input: Clock signal for port A.
        .ena(1'b1),                       // 1-bit input: Memory enable signal for port A. Must be high on clock cycles when read operations are
                                          // initiated. Pipelined internally.

        .injectdbiterra(1'b0),  // 1-bit input: Do not change from the provided value.
        .injectsbiterra(1'b0),  // 1-bit input: Do not change from the provided value.
        .regcea(1'b1),  // 1-bit input: Do not change from the provided value.
        .rsta(1'b0),                     // 1-bit input: Reset signal for the final port A output register stage. Synchronously resets output port
                                         // douta to the value specified by parameter READ_RESET_VALUE_A.

        .sleep(1'b0)  // 1-bit input: sleep signal to enable the dynamic power saving feature.
    );




endmodule
