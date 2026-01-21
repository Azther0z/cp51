module debouncer #(
    SAMPLING_RATE = 3,
    COUNTER_WIDTH = 2
) (
    input  clk,
    input  rst,
    input  data_in,
    output data_out
);
    // TODO: Implement debouncing module using sampling technique
    reg [COUNTER_WIDTH-1:0] counter;
    reg out_reg = 0;
    assign data_out = out_reg;
    always @(posedge(clk))begin
        if (rst==1) begin
            counter <= SAMPLING_RATE-1;
            out_reg <= 0;
        end else if(counter>0)begin
            counter <= counter-1;
        end else begin
            if (data_in==1) begin
                counter <= SAMPLING_RATE-1;
                out_reg <= 1;
            end else begin
                out_reg <= 0;
            end
        end
    end 


endmodule
