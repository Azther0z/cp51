module lfsr_16 (
    input  wire        clk,
    input  wire        reset,
    input  wire        enable,
    output wire [15:0] lfsr_out
);

`ifdef COCOTB_SIM
    initial begin
        $dumpfile("waveform.vcd");  // Name of the dump file
        $dumpvars(0, lfsr_16);  // Dump all variables for the top module
    end
`endif

    reg  [15:0] lfsr_reg;
    wire        in = (lfsr_reg[3] ^ lfsr_reg[12]) ^ (lfsr_reg[14] ^ lfsr_reg[15]);
    assign lfsr_out = lfsr_reg;

    always @(posedge clk) begin
        if (reset) begin
            lfsr_reg <= 16'hFFFF;
        end else if (enable) begin
            lfsr_reg <= {lfsr_reg[14:0], in};
        end
    end

endmodule
