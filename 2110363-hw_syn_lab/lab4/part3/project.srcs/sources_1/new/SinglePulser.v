module SinglePulser #(
    SAMPLING_RATE = 3,
    COUNTER_WIDTH = 2
) (
    input  clock,
    input  reset,   // Active high
    input  dataIn,  // Active high
    output dataOut
);
    reg [COUNTER_WIDTH-1:0] counter;
    reg                     outReg = 0;
    reg                     prevReg = 0;
    assign dataOut = outReg;
    always @(posedge (clock)) begin
        if (reset) begin
            counter <= SAMPLING_RATE - 1;
            outReg = 0;
        end else if (counter > 0) begin
            counter <= counter - 1;
            outReg = 0;
        end else begin
            if (dataIn && !prevReg) begin
                prevReg <= 1;
                outReg  <= 1;
                counter <= SAMPLING_RATE - 1;
            end else if (!dataIn) begin
                prevReg <= 0;
            end
        end
    end
endmodule
