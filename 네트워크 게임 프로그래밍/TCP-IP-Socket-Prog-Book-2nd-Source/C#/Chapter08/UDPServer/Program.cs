﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;

namespace UDPServer
{
    class Program
    {
        const int SERVERPORT = 9000;
        const int BUFSIZE = 512;

        static void Main(string[] args)
        {
            int retval;

            Socket sock = null;
            try
            {
                // 소켓 생성
                sock = new Socket(AddressFamily.InterNetwork,
                    SocketType.Dgram, ProtocolType.Udp);

                // Bind()
                sock.Bind(new IPEndPoint(IPAddress.Any, SERVERPORT));
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Environment.Exit(1);
            }

            // 데이터 통신에 사용할 변수
            byte[] buf = new byte[BUFSIZE];

            while (true)
            {
                try
                {
                    // 데이터 받기
                    IPEndPoint anyaddr = new IPEndPoint(IPAddress.Any, 0);
                    EndPoint peeraddr = (EndPoint)anyaddr;
                    retval = sock.ReceiveFrom(buf, BUFSIZE,
                        SocketFlags.None, ref peeraddr);

                    // 받은 데이터 출력
                    Console.WriteLine("[UDP/{0}:{1}] {2}",
                        ((IPEndPoint)peeraddr).Address,
                        ((IPEndPoint)peeraddr).Port,
                        Encoding.Default.GetString(buf, 0, retval));

                    // 데이터 보내기
                    sock.SendTo(buf, 0, retval, SocketFlags.None, peeraddr);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                    break;
                }
            }

            // 소켓 닫기
            sock.Close();
        }
    }
}
