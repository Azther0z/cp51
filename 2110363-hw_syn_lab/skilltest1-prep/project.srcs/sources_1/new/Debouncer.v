module Debouncer (
    input  dataIn,
    input  reset,
    input  clock,
    output dataOut
);
    reg outReg;
    reg prevReg;
    assign dataOut = outReg;
    reg [8:0] counter;
    initial begin
        outReg  <= 0;
        counter <= 0;
        prevReg <= 0;
    end
    always @(posedge clock) begin
        if (reset) begin
            counter <= 0;
            prevReg <= 0;
        end else if (!reset && counter) begin
            counter <= counter - 1;
            outReg  <= 0;
        end else if (!reset && !counter && dataIn && !prevReg) begin
            counter <= 9'b111111111;
            outReg  <= 1;
            prevReg <= 1;
        end else if (!reset && !counter && !dataIn) begin
            prevReg <= 0;
        end
    end

endmodule
