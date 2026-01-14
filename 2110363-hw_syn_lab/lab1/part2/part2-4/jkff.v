module jkff (
    input  J,
    input  K,
    input  clk,
    output Q
);
    // TODO: Implement the JK flip-flop behavior
    reg q = 0;
    assign Q = q;
    always @(posedge clk) begin
        case({J,K}) 
            2'b00: q <= q;
            2'b01: q <= 0;
            2'b10: q <= 1;
            2'b11: q <= ~q;
        endcase
    end

endmodule
