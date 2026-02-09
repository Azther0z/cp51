module Trigger (
    input  [ 3:0] trigger,
    input         reset,
    input         clock,
    output [15:0] value
);
    reg [15:0] valueReg;
    assign value = valueReg;
    initial begin
        valueReg = 1;
    end
    always @(posedge clock) begin
        if (reset) begin
            valueReg <= 1;
        end else if (!reset && valueReg <= 9999) begin
            case (trigger)
                4'b0001: valueReg <= valueReg + 1;
                4'b0010: valueReg <= valueReg + 2;
                4'b0100: valueReg <= valueReg * 2;
                4'b1000: valueReg <= valueReg * 3;
                default: ;
            endcase
        end
    end
endmodule
