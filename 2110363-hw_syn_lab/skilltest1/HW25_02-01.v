module bcd_addsub (
    input  wire [3:0] a_i,
    input  wire [3:0] b_i,
    input  wire       addsub,      // 0=Add, 1=Sub
    output reg  [3:0] sum_o,
    output reg        carry_o,
    input  wire [3:0] testcase_no  // for testbench use only
);
    // Note : Do not use testcase_no in your design logic
    // testcase_no is only for testbench purposes

    // add your code here
    wire [4:0] result = (addsub ? a_i - b_i : a_i + b_i);
    always @(*) begin
        sum_o   <= result % 10;
        carry_o <= result / 10;
    end
endmodule
