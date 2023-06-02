namespace NetworkArchitect
{
	public struct Vertex
	{
		public string Name;
	}

	public struct Edge
		{
		public Vertex v1;
		public Vertex v2;
		public int Weight;

	}

	public class Network
	{
		public Network()
		{
			
		}
		



		public void AddEdge(Vertex x, Vertex y, int weight)
		{
			Edge e = new Edge();
			e.v1 = x;
			e.v2 = y;
			e.Weight = weight;
			Edges.Add(e);
			if (!Vertices.Contains(x))
			{
				Vertices.Add(x);
			}
			//Vertices.Add(x);
			Vertices.Add(y);
			EnterConnection(x, y);
			EnterConnection(y, x);
			CableNeeded += e.Weight;
		}

		private void EnterConnection(Vertex x, Vertex y)
		{
			if (Connections.ContainsKey(x))
			{
				Connections[x].Add(y);
			}
			else
			{
				Connections.Add(x, new List<Vertex>());
				Connections[x].Add(y);
			}
		}

		private bool AreConnected(Vertex x, Vertex y)
		{	Queue<Vertex> q = new Queue<Vertex>();
			List<Vertex> visited = new List<Vertex>();
			q.Enqueue(x);
			while (q.Count > 0)
			{
				Vertex v = q.Dequeue();
				if (v.Name == y.Name)
				{
					return true;
				}
				else
				{
					if (Connections.ContainsKey(v))
					{
						visited.Add(v);
						foreach (Vertex v2 in Connections[v])
						{
							if (!visited.Contains(v2))
							{
								q.Enqueue(v2);
							}
						}
					}
				}
			}
			return false;
		}
		

		public Network MSTKruskal()
		{
			Network MST = new Network();
			List<Edge> sortedEdges = Edges.OrderBy(x => x.Weight).ToList();
			for (int i = 0; i < sortedEdges.Count; i++)
			{
				Edge e = sortedEdges[i];
				if (!MST.AreConnected(e.v1, e.v2))
				{
					MST.AddEdge(e.v1, e.v2, e.Weight);
				}
			}
			return MST;
		}

		private List<Edge> enqueueEdges(Vertex v, List<Edge> q)
		{
			foreach (Edge e in Edges)
			{
				if (e.v1.Name == v.Name || e.v2.Name == v.Name)
				{
					q.Add(e);
				}
			}
			q.Sort((x, y) => x.Weight.CompareTo(y.Weight));
			return q;
		}

		public Network MSTPrim()
		{
			Network MST = new Network();
			List<Edge> pq = new List<Edge>();
			List<Vertex> visited = new List<Vertex>();
			Vertex v = Vertices[0];
			visited.Add(v);
			//enqueue all edges connected to v
			pq = enqueueEdges(v, pq);
			
			while (pq.Count > 0)
			{
				Edge e = pq[0];
				pq.RemoveAt(0);

				if (!MST.AreConnected(e.v1, e.v2))
				{
					MST.AddEdge(e.v1, e.v2, e.Weight);
					if (!visited.Contains(e.v1))
					{
						visited.Add(e.v1);
						pq = enqueueEdges(e.v1, pq);
					}
					else if (!visited.Contains(e.v2))
					{
						visited.Add(e.v2);
						pq = enqueueEdges(e.v2, pq);
					}

				}


			}
			return MST;

		}




		public List<Edge> Edges = new List<Edge>();
		public List<Vertex> Vertices = new List<Vertex>();
		private Dictionary<Vertex, List<Vertex>> Connections = new Dictionary<Vertex, List<Vertex>>();
		public int CableNeeded=0;

	}
}