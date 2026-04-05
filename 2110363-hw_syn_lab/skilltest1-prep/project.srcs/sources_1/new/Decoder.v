module Decoder (
    input  [15:0] value,
    input         clock,
    output [ 3:0] bcd0,
    output [ 3:0] bcd1,
    output [ 3:0] bcd2,
    output [ 3:0] bcd3
);
    // reg [3:0] reg0;
    // reg [3:0] reg1;
    // reg [3:0] reg2;
    // reg [3:0] reg3;
    // assign bcd0 = reg0;
    // assign bcd1 = reg1;
    // assign bcd2 = reg2;
    // assign bcd3 = reg3;
    // always @(posedge clock) begin
    //     if (value <= 9999) begin
    //         reg0 <= value % 10;
    //         reg1 <= (value / 10) % 10;
    //         reg2 <= (value / 100) % 10;
    //         reg3 <= value / 1000;
    //     end else begin
    //         reg0 <= 4'b1111;
    //         reg1 <= 4'b1111;
    //         reg2 <= 4'b1111;
    //         reg3 <= 4'b1111;
    //     end
    // end
    assign bcd0 = value < 10000 ? value % 10 : 4'b1111;
    assign bcd1 = value < 10000 ? (value / 10) % 10 : 4'b1111;
    assign bcd2 = value < 10000 ? (value / 100) % 10 : 4'b1111;
    assign bcd3 = value < 10000 ? value / 1000 : 4'b1111;
endmodule
