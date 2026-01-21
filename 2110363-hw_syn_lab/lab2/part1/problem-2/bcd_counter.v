module bcd_counter (
    input        clk,
    input        rst,
    output [3:0] q,
    output       cout
);
    // TODO: Implement BCD counter
    reg [3:0] q_reg;
    reg cout_reg;
    assign q = q_reg;
    assign cout = cout_reg;
    initial begin
        q_reg = 0;
        cout_reg = 0;
    end
    always @(posedge(clk))begin
        if(rst==1) begin
            q_reg <= 0;
            cout_reg <= 0;
        end else if (q_reg==9) begin
            q_reg <= 0;
            cout_reg <= 0;
        end else if (q_reg==8) begin
            q_reg <= q_reg+1;
            cout_reg <= 1;
        end else begin
            q_reg <= q_reg+1;
        end
    end


endmodule
