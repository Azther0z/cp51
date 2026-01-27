`timescale 1ns / 1ns

module fsm_tb ();
    // Create wires and regs to connect to the DUT
    reg        clk;
    reg        reset;
    reg        data_in;
    wire [1:0] data_out;

    // TODO: instantiate the DUT and write the testbench logic
    fsm dut (
        .clk     (clk),
        .rst     (reset),
        .data_in (data_in),
        .data_out(data_out)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        reset = 1;
        #10;
        reset   = 0;
        // A->B
        data_in = 1;
        #10;
        // B->C
        data_in = 1;
        #10;
        // C->D
        data_in = 0;
        #10;
        // D->A
        data_in = 0;
        #10;
        // A->D
        data_in = 0;
        #10;
        // D->B
        data_in = 1;
        #10;
        // B->D
        data_in = 0;
        #10;
        // A->B->C->B
        reset = 1;
        #10;
        reset   = 0;
        data_in = 1;
        #10;
        data_in = 1;
        #10;
        data_in = 1;
        #10;
        $finish;
    end

    // -- Do not delete the lines below --
    // Dump waveforms
    initial begin
        $dumpfile("fsm_tb.vcd");
        $dumpvars(0, fsm_tb);
    end

endmodule
