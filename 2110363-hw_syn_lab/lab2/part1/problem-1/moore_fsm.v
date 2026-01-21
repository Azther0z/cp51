module moore_fsm (
    input        clk,
    input        rst,
    input        in,
    output [2:0] out
);
    // TODO: Implement the Moore FSM logic here
    reg [2:0] state = 3'b000;
    assign out = state;
    always @(posedge clk) begin
        if(rst==1)begin
            state = 3'b000;
        end else if(state==3'b000)begin
            state = 3'b011;
        end else if(state==3'b011)begin
            if(in==0) state = 3'b010;
            else state = 3'b100;
        end else if(state==3'b100)begin
            if(in==0) state = 3'b011;
            else state = 3'b101;
        end else if(state==3'b101)begin
            if(in==0) state = 3'b100;
            else state = 3'b001;
        end else if(state==3'b010)begin
            if(in==0) state = 3'b001;
            else state = 3'b011;
        end 
    end 

endmodule
