`timescale 1ns / 1ps

module data_generator (
    input  wire        s_axis_aclk,
    input  wire        s_axis_rst,
    // AXI Stream Slave Interface
    input  wire [ 7:0] s_axis_tdata,
    input  wire        s_axis_tvalid,
    output reg         s_axis_tready,
    // AXI Stream Master Interface
    output reg  [31:0] m_axis_tdata,
    output reg         m_axis_tvalid,
    input  wire        m_axis_tready,
    output reg  [ 3:0] m_axis_tkeep,
    output reg         m_axis_tlast,
    // For Waveform debugging not used
    input  wire [ 9:0] testcase_id
);

    // Add your code here
    localparam IDLE = 1'b0;
    localparam GEN = 1'b1;

    reg state;
    reg [7:0] total, sent;
    wire [7:0] remain = total - sent;

    always @(posedge s_axis_aclk) begin
        if (s_axis_rst) begin
            state         <= IDLE;
            s_axis_tready <= 0;
            m_axis_tvalid <= 0;
            m_axis_tlast  <= 0;
            m_axis_tdata  <= 0;
            m_axis_tkeep  <= 0;
            sent          <= 0;
            total         <= 0;
        end else begin
            case (state)
                IDLE: begin
                    s_axis_tready <= 1;
                    if (s_axis_tvalid && s_axis_tready) begin
                        state         <= GEN;
                        s_axis_tready <= 0;
                        sent          <= 0;
                        total         <= s_axis_tdata;
                    end
                end

                GEN: begin
                    m_axis_tvalid       <= 1'b1;
                    m_axis_tdata[7:0]   <= sent;
                    m_axis_tdata[15:8]  <= sent + 1;
                    m_axis_tdata[23:16] <= sent + 2;
                    m_axis_tdata[31:24] <= sent + 3;
                    case (remain)
                        0:       m_axis_tkeep <= 4'b0000;
                        1:       m_axis_tkeep <= 4'b0001;
                        2:       m_axis_tkeep <= 4'b0011;
                        3:       m_axis_tkeep <= 4'b0111;
                        default: m_axis_tkeep <= 4'b1111;
                    endcase
                    if (4 >= remain) begin
                        m_axis_tlast <= 1'b1;
                    end
                    if (m_axis_tready) begin
                        if (m_axis_tlast) begin
                            m_axis_tvalid <= 1'b0;
                            m_axis_tlast  <= 1'b0;
                            state         <= IDLE;
                        end else begin
                            sent <= sent + 4;
                        end
                    end
                end
            endcase
        end
    end

endmodule
