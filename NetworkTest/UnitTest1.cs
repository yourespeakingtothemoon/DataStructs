using System.Net.Sockets;
using System.Runtime.Intrinsics.X86;

namespace NetworkTest
{
	[TestClass]
	public class UnitTest1
	{
		[TestMethod]
		public void NetworkTest1()
		{
			NetworkArchitect.Network n = new NetworkArchitect.Network();
			NetworkArchitect.Vertex ax1 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax2 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax3 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax4 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax5 = new NetworkArchitect.Vertex();
			ax1.Name = "AX1";
			ax2.Name = "AX2";
			ax3.Name = "AX3";
			ax4.Name = "AX4";
			ax5.Name = "AX5";
			//AX1,AX4: 3,AX2: 3,AX3: 6
			n.AddEdge(ax1, ax4, 3);
			n.AddEdge(ax1, ax2, 3);
			n.AddEdge(ax1, ax3, 6);
			//AX2,AX1: 3,AX3: 3,AX4: 6
				//n.AddEdge(ax2, ax1, 3);
			n.AddEdge(ax2, ax3, 3);
			n.AddEdge(ax2, ax4, 6);
			//AX3,AX2: 3,AX1: 6,AX4: 4
				//n.AddEdge(ax3, ax2, 3);
				//n.AddEdge(ax3, ax1, 6);
			n.AddEdge(ax3, ax4, 4);
			//AX4,AX1: 3,AX2: 6,AX3: 4,AX5: 15
				//n.AddEdge(ax4, ax1, 3);
				//n.AddEdge(ax4, ax2, 6);
				//n.AddEdge(ax4, ax3, 4);
			n.AddEdge(ax4, ax5, 15);
			//AX5,AX4: 15

			//Socket Set: AX1, AX4, AX2, AX3, AX5
			//Cable Needed: 24ft

			NetworkArchitect.Network MST = n.MSTKruskal();
			Assert.AreEqual(24, MST.CableNeeded);

			//Socket Set: AX1, AX4, AX2, AX3, AX5
			//build string of socket names like this for MST

			string socketNames = "";
			foreach (NetworkArchitect.Vertex v in MST.Vertices)
			{
				socketNames += v.Name + ",";
			}
			socketNames = socketNames.TrimEnd(',');
			Assert.AreEqual("AX1,AX4,AX2,AX3,AX5", socketNames);


		}


		[TestMethod]
		public void NetworkTest2()
		{
			NetworkArchitect.Network n = new NetworkArchitect.Network();
			//AX10,AX11,AX12,AX99,AX100
			NetworkArchitect.Vertex ax10 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax11 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax12 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax99 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax100 = new NetworkArchitect.Vertex();
			ax10.Name = "AX10";
			ax11.Name = "AX11";
			ax12.Name = "AX12";
			ax99.Name = "AX99";
			ax100.Name = "AX100";

			//AX10, AX11:2,AX12: 4
			n.AddEdge(ax10, ax11, 2);
			n.AddEdge(ax10, ax12, 4);
			//AX11,AX10: 2,AX12: 2
			n.AddEdge(ax11, ax12, 2);
			//AX12,AX10: 4,AX11: 2,AX99: 4
			n.AddEdge(ax12, ax99, 4);
			//AX99,AX12: 4,AX100: 15
			n.AddEdge(ax99, ax100, 15);
			//AX100,AX99: 15

			NetworkArchitect.Network MST = n.MSTKruskal();


			//EXPECTED OUT
			//Socket Set: AX10, AX11, AX12, AX99, AX100
			//Cable Needed: 23f
			Assert.AreEqual(23, MST.CableNeeded);

			

			string socketNames = "";
			foreach (NetworkArchitect.Vertex v in MST.Vertices)
			{
				socketNames += v.Name + ",";
			}
			socketNames = socketNames.TrimEnd(',');
			Assert.AreEqual("AX10,AX11,AX12,AX99,AX100", socketNames);
		}

		[TestMethod]
		public void NetworkTest1Prim()
		{
			NetworkArchitect.Network n = new NetworkArchitect.Network();
			NetworkArchitect.Vertex ax1 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax2 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax3 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax4 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax5 = new NetworkArchitect.Vertex();
			ax1.Name = "AX1";
			ax2.Name = "AX2";
			ax3.Name = "AX3";
			ax4.Name = "AX4";
			ax5.Name = "AX5";
			//AX1,AX4: 3,AX2: 3,AX3: 6
			n.AddEdge(ax1, ax4, 3);
			n.AddEdge(ax1, ax2, 3);
			n.AddEdge(ax1, ax3, 6);
			//AX2,AX1: 3,AX3: 3,AX4: 6
			//n.AddEdge(ax2, ax1, 3);
			n.AddEdge(ax2, ax3, 3);
			n.AddEdge(ax2, ax4, 6);
			//AX3,AX2: 3,AX1: 6,AX4: 4
			//n.AddEdge(ax3, ax2, 3);
			//n.AddEdge(ax3, ax1, 6);
			n.AddEdge(ax3, ax4, 4);
			//AX4,AX1: 3,AX2: 6,AX3: 4,AX5: 15
			//n.AddEdge(ax4, ax1, 3);
			//n.AddEdge(ax4, ax2, 6);
			//n.AddEdge(ax4, ax3, 4);
			n.AddEdge(ax4, ax5, 15);
			//AX5,AX4: 15

			//Socket Set: AX1, AX4, AX2, AX3, AX5
			//Cable Needed: 24ft

			NetworkArchitect.Network MST = n.MSTPrim();
			Assert.AreEqual(24, MST.CableNeeded);

			//Socket Set: AX1, AX4, AX2, AX3, AX5
			//build string of socket names like this for MST

			string socketNames = "";
			foreach (NetworkArchitect.Vertex v in MST.Vertices)
			{
				socketNames += v.Name + ",";
			}
			socketNames = socketNames.TrimEnd(',');
			Assert.AreEqual("AX1,AX4,AX2,AX3,AX5", socketNames);


		}


		[TestMethod]
		public void NetworkTest2Prim()
		{
			NetworkArchitect.Network n = new NetworkArchitect.Network();
			//AX10,AX11,AX12,AX99,AX100
			NetworkArchitect.Vertex ax10 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax11 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax12 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax99 = new NetworkArchitect.Vertex();
			NetworkArchitect.Vertex ax100 = new NetworkArchitect.Vertex();
			ax10.Name = "AX10";
			ax11.Name = "AX11";
			ax12.Name = "AX12";
			ax99.Name = "AX99";
			ax100.Name = "AX100";

			//AX10, AX11:2,AX12: 4
			n.AddEdge(ax10, ax11, 2);
			n.AddEdge(ax10, ax12, 4);
			//AX11,AX10: 2,AX12: 2
			n.AddEdge(ax11, ax12, 2);
			//AX12,AX10: 4,AX11: 2,AX99: 4
			n.AddEdge(ax12, ax99, 4);
			//AX99,AX12: 4,AX100: 15
			n.AddEdge(ax99, ax100, 15);
			//AX100,AX99: 15

			NetworkArchitect.Network MST = n.MSTPrim();


			//EXPECTED OUT
			//Socket Set: AX10, AX11, AX12, AX99, AX100
			//Cable Needed: 23f
			Assert.AreEqual(23, MST.CableNeeded);



			string socketNames = "";
			foreach (NetworkArchitect.Vertex v in MST.Vertices)
			{
				socketNames += v.Name + ",";
			}
			socketNames = socketNames.TrimEnd(',');
			Assert.AreEqual("AX10,AX11,AX12,AX99,AX100", socketNames);
		}
	}
}