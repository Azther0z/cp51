module dff_sync_reset (
    input  clk,
    input  rst,
    input  D,
    output Q
);
    // TODO: Implement the D flip-flop with synchronous reset behavior here
    reg q;
    assign Q = q;
    always @(posedge clk) begin
        if(rst)
            q <= 0;
        else
            q <= D;
    end

endmodule