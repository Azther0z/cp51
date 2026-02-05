module SegmentMap (
    input      [3:0] digit,
    output reg [7:0] enable
);
    always @(*) begin
        case (digit)
            0:       enable = 8'b00000011;
            1:       enable = 8'b10011111;
            2:       enable = 8'b00100101;
            3:       enable = 8'b00001101;
            4:       enable = 8'b10011001;
            5:       enable = 8'b01001001;
            6:       enable = 8'b01000001;
            7:       enable = 8'b00011111;
            8:       enable = 8'b00000001;
            9:       enable = 8'b00001001;
            10:      enable = 8'b00010001;
            11:      enable = 8'b11000001;
            12:      enable = 8'b01100011;
            13:      enable = 8'b10000101;
            14:      enable = 8'b01100001;
            15:      enable = 8'b01110001;
            default: enable = 8'b11111111;
        endcase
    end
endmodule

module SevenSegment (
    input        clock,
    input        reset,           // Active high
    input  [3:0] digit1,          // Rightmost digit
    input  [3:0] digit2,
    input  [3:0] digit3,
    input  [3:0] digit4,          // Leftmost digit
    output [3:0] digitSelector,   // Digit selector, active low
    output [7:0] segmentSelector  // Segment selector, active low
);
    reg [7:0] enableReg;
    assign segmentSelector = enableReg;
    wire [7:0] enable1, enable2, enable3, enable4;
    SegmentMap map1 (
        .digit (digit1),
        .enable(enable1)
    );
    SegmentMap map2 (
        .digit (digit2),
        .enable(enable2)
    );
    SegmentMap map3 (
        .digit (digit3),
        .enable(enable3)
    );
    SegmentMap map4 (
        .digit (digit4),
        .enable(enable4)
    );
    reg [19:0] counter = 0;
    reg [ 3:0] selector;
    assign digitSelector = selector;
    always @(posedge (clock)) begin
        if (reset) begin
            counter   <= 0;
            selector  <= 4'b0000;
            enableReg <= 8'b11111111;
        end else begin
            case (counter[19:18])
                0: begin
                    selector  = 4'b0111;
                    enableReg = enable4;
                end
                1: begin
                    selector  = 4'b1011;
                    enableReg = enable3;
                end
                2: begin
                    selector  = 4'b1101;
                    enableReg = enable2;
                end
                3: begin
                    selector  = 4'b1110;
                    enableReg = enable1;
                end
                default: begin
                    selector  = 4'b0000;
                    enableReg = 8'b11111111;
                end
            endcase
        end
        counter = counter + 1;
    end

endmodule
