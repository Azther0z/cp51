`timescale 1ns / 1ns

module full_adder_4_bits_tb ();
    // Create wires and regs to connect to the DUT
    reg  [3:0] a;
    reg  [3:0] b;
    reg        cin;
    wire [3:0] sum;
    wire       cout;

    // TODO: instantiate the DUT and write the testbench logic
    full_adder_4_bits dut (
        .a   (a),
        .b   (b),
        .cin (cin),
        .sum (sum),
        .cout(cout)
    );

    initial begin
        for (integer i = 0; i < 16; i = i + 1) begin
            for (integer j = 0; j < 16; j = j + 1) begin
                for (integer k = 0; k < 2; k = k + 1) begin
                    a   = i;
                    b   = j;
                    cin = k;
                    #10;
                end
            end
        end
        $finish;
    end

    // -- Do not delete the lines below --
    // Dump waveforms
    initial begin
        $dumpfile("full_adder_4_bits_tb.vcd");
        $dumpvars(0, full_adder_4_bits_tb);
    end

endmodule
