module stack_calc (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [15:0] data_i,
    input  wire        push,
    input  wire        pop,
    input  wire        calculate,
    output reg  [15:0] data_o,
    output reg  [ 8:0] count_o,     // 9 bits needed for range 0-256
    input  wire [ 3:0] testcase_no  // for testbench use only
);
    // Note : Do not use testcase_no in your design logic
    // testcase_no is only for testbench purposes

    // add your code here
    reg [15:0] mem[0:255];
    reg prevPush, prevPop, prevCalc;
    initial begin
        count_o  <= 0;
        data_o   <= 0;
        prevCalc <= 0;
        prevPop  <= 0;
        prevPush <= 0;
    end

    always @(rst_n) begin
        count_o  <= 0;
        data_o   <= 0;
        prevCalc <= 0;
        prevPop  <= 0;
        prevPush <= 0;
    end

    always @(posedge clk) begin
        if (!prevPush && push && count_o < 256) begin
            mem[count_o] = data_i;
            count_o      = count_o + 1;
            prevPush     = 1;
        end else if (!prevPop && pop && count_o) begin
            data_o  = mem[count_o-1];
            count_o = count_o - 1;
            prevPop = 1;
        end else if (!prevCalc && calculate && count_o >= 2) begin
            mem[count_o-2] = mem[count_o-2] + mem[count_o-1];
            count_o        = count_o - 1;
            prevCalc       = 1;
        end
        if (!push) prevPush = 0;
        if (!pop) prevPop = 0;
        if (!calculate) prevCalc = 0;
    end

endmodule
