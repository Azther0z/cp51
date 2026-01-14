module xnor_xor (
    input  wire in1,
    input  wire in2,
    input  wire in3,
    output wire out
);
    // TODO: Implement the logic here
    assign w1 = in1~^in2;
    assign out = w1^in3;

endmodule