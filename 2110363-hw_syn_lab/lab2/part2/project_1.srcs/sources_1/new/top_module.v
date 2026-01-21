`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/21/2026 11:20:27 AM
// Design Name: 
// Module Name: top_module
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module segment_map(
    input [3:0] digit,
    output reg [7:0] enable
);
    always @(*)begin
        case(digit)
            0: enable = 8'b00000011;
            1: enable = 8'b10011111;
            2: enable = 8'b00100101;
            3: enable = 8'b00001101;
            4: enable = 8'b10011001; 
            5: enable = 8'b01001001; 
            6: enable = 8'b01000001; 
            7: enable = 8'b00011111; 
            8: enable = 8'b00000001; 
            9: enable = 8'b00001001; 
            10:  enable = 8'b00010001;
            11:  enable = 8'b11000001;
            12:  enable = 8'b01100011;
            13:  enable = 8'b10000101;
            14:  enable = 8'b01100001;
            15:  enable = 8'b01110001;
        endcase 
    end
endmodule

module top_module(
    input [3:0] digit1,
    input [3:0] digit2,
    input [3:0] digit3,
    input [3:0] digit4,
    input clk,
    input rst,
    output [3:0] AN,
    output [7:0] CX
);
    reg [7:0] enable_reg;
    assign CX = enable_reg;
    wire [7:0] enable1, enable2, enable3, enable4;
    segment_map map1(.digit(digit1),.enable(enable1));
    segment_map map2(.digit(digit2),.enable(enable2));
    segment_map map3(.digit(digit3),.enable(enable3));
    segment_map map4(.digit(digit4),.enable(enable4));
    reg [19:0] counter = 0;
    reg [3:0] selector;
    assign AN = selector;
    always @(posedge(clk)) begin
        if(rst==1)begin
            counter <= 0;
            selector <= 0;
            enable_reg <= 0;
        end else begin
            case (counter[19:18])
                0: begin
                    selector = 4'b0111;
                    enable_reg = enable4;
                end
                1: begin
                    selector = 4'b1011;
                    enable_reg = enable3;
                end
                2: begin
                    selector = 4'b1101;
                    enable_reg = enable2;
                end
                3: begin
                    selector = 4'b1110;
                    enable_reg = enable1;
                end
            endcase
        end
        counter = counter+1;
    end

endmodule
