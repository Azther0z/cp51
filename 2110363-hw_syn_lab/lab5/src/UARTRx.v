module UARTRx (
    input  wire       Clk,
    input  wire       Reset,
    input  wire       Rx,
    output reg  [7:0] DataOut,
    output reg        DataValid,
    input  wire       DataReady
);
    // Add your code here
    localparam PERIOD = 868;
    localparam HALF = 434;
    localparam IDLE = 0;
    localparam START_BIT = 1;
    localparam DATA_BIT = 2;
    localparam STOP_BIT = 3;
    localparam VALID_DATA = 4;
    reg [2:0] state;
    reg [7:0] buffer;
    reg [9:0] periodCounter;
    reg [2:0] index;

    always @(posedge Clk) begin
        if (Reset) begin
            state <= IDLE;
        end else begin
            case (state)
                IDLE: begin
                    if (!Rx) begin
                        state         <= START_BIT;
                        periodCounter <= HALF;
                    end
                end
                START_BIT: begin
                    if (periodCounter) begin
                        periodCounter <= periodCounter - 1;
                    end else if (!periodCounter && !Rx) begin
                        state         <= DATA_BIT;
                        periodCounter <= PERIOD;
                        index         <= 0;
                    end else if (!periodCounter && Rx) begin
                        state <= IDLE;
                    end
                end
                DATA_BIT: begin
                    if (periodCounter) begin
                        periodCounter <= periodCounter - 1;
                    end else if (!periodCounter && index != 7) begin
                        periodCounter <= PERIOD;
                        buffer[index] <= Rx;
                        index         <= index + 1;
                    end else if (!periodCounter && index == 7) begin
                        periodCounter <= PERIOD;
                        buffer[index] <= Rx;
                        state         <= STOP_BIT;
                    end
                end
                STOP_BIT: begin
                    if (periodCounter) begin
                        periodCounter <= periodCounter - 1;
                    end else if (!periodCounter && Rx) begin
                        DataOut   <= buffer;
                        DataValid <= 1;
                        state     <= VALID_DATA;
                    end else if (!periodCounter && !Rx) begin
                        state <= IDLE;
                    end
                end
                VALID_DATA: begin
                    if (!DataReady) begin
                        DataValid <= 1;
                    end else begin
                        DataValid <= 0;
                        state     <= IDLE;
                    end
                end
                default: ;
            endcase
        end
    end
    // End of your code
endmodule
