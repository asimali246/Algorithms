import java.io.*;  
import java.math.*;
import java.util.*;
import java.util.regex.*;
class Main
{
	int radodd[]=new int[100011];
	int radeven[]=new int[100011];
	int phi[]={0,1,1,2,2,4,2,6,4,6,4,10,4,12,6,8,8,16,6,18,8,12,10,22,8,20,12,18,12,28,8,30,16,20,16,24,12,36,18,24,16,40,12,42,20,24,22,46,16,42,20,32,24,52,18,40,24,36,28,58,16,60,30,36,32,48,20,66,32,44,24,70,24,72,36,40,36,60,24,78,32,54,40,82,24,64,42,56,40,88,24,72,44,60,46,72,32,96,42,60,40,100,32,102,48,48,52,106,36,108,40,72,48,112,36,88,56,72,58,96,32,110,60,80,60,100,36,126,64,84,48,130,40,108,66,72,64,136,44,138,48,92,70,120,48,112,72,84,72,148,40,150,72,96,60,120,48,156,78,104,64,132,54,162,80,80,82,166,48,156,64,108,84,172,56,120,80,116,88,178,48,180,72,120,88,144,60,160,92,108,72,190,64,192,96,96,84,196,60,198,80,132,100,168,64,160,102,132,96,180,48,210,104,140,106,168,72,180,108,144,80,192,72,222,96,120,112,226,72,228,88,120,112,232,72,184,116,156,96,238,64,240,110,162,120,168,80,216,120,164,100,250,72,220,126,128,128,256,84,216,96,168,130,262,80,208,108,176,132,268,72,270,128,144,136,200,88,276,138,180,96,280,92,282,140,144,120,240,96,272,112,192,144,292,84,232,144,180,148,264,80,252,150,200,144,240,96,306,120,204,120,310,96,312,156,144,156,316,104,280,128,212,132,288,108,240,162,216,160,276,80,330,164,216,166,264,96,336,156,224,128,300,108,294,168,176,172,346,112,348,120,216,160,352,116,280,176,192,178,358,96,342,180,220,144,288,120,366,176,240,144,312,120,372,160,200,184,336,108,378,144,252,190,382,128,240,192,252,192,388,96,352,168,260,196,312,120,396,198,216,160,400,132,360,200,216,168,360,128,408,160,272,204,348,132,328,192,276,180,418,96,420,210,276,208,320,140,360,212,240,168,430,144,432,180,224,216,396,144,438,160,252,192,442,144,352,222,296,192,448,120,400,224,300,226,288,144,456,228,288,176,460,120,462,224,240,232,466,144,396,184,312,232,420,156,360,192,312,238,478,128,432,240,264,220,384,162,486,240,324,168,490,160,448,216,240,240,420,164,498,200,332,250,502,144,400,220,312,252,508,128,432,256,324,256,408,168,460,216,344,192,520,168,522,260,240,262,480,160,506,208,348,216,480,176,424,264,356,268,420,144,540,270,360,256,432,144,546,272,360,200,504,176,468,276,288,276,556,180,504,192,320,280,562,184,448,282,324,280,568,144,570,240,380,240,440,192,576,272,384,224,492,192,520,288,288,292,586,168,540,232,392,288,592,180,384,296,396,264,598,160};
	int n, nn, i, j, ans, l, h, sz, u, len, ii, nnn;
	char texto[]=new char[100011];
	char texte[]=new char[100011];
	int nmax=100010;
	char s[]=new char[nmax];
	int head, tail;
	node t[]=new node[2*nmax+1];
	int szt;
	node root=new node();
	position pos=new position();
	Deque<Integer> suffixes=new ArrayDeque<Integer>();
	int leng(int v)
	{
		return t[v].r-t[v].l;
	}
	int add_edge_to_parent(int l, int r, int parent)
	{
		int nidx=szt++;
		t[nidx]=new node(l, r, parent, t[parent].dep+(r-l));
		if(r==nmax)
		{
			t[nidx].idx=Math.max(t[parent].idx, t[nidx].idx);
		}
		t[parent].next.put(s[l], nidx);
		return nidx;
	}
	int add_edge_to_parent_idx(int l, int r, int parent, int nidx)
	{
		t[nidx].l=l;
		t[nidx].r=r;
		t[nidx].par=parent;
		t[nidx].dep=t[parent].dep+(r-l);
		if(r==nmax)
		{
			t[nidx].idx=nmax-t[nidx].dep;
			t[parent].idx=Math.max(t[parent].idx, t[nidx].idx);
		}
		t[parent].next.put(s[l], nidx);
		return nidx;
	}
	int split_edge(position pos)
	{
		int v=pos.V, up=pos.L, down=leng(v)-up;
		if(up==0)
			return v;
		if(down==0)
			return t[v].par;
		int mid=add_edge_to_parent(t[v].l, t[v].l+down, t[v].par);
		t[v].l+=down;
		t[v].par=mid;
		t[mid].next.put(s[t[v].l], v);
		t[mid].idx=t[v].idx;
		return mid;
	}
	position read_char(position pos, char c)
	{
		int v=pos.V, up=pos.L;
		if(up>0)
			return s[t[v].r-up]==c?new position(v, up-1, pos.dep+1): new position(-1, -1, -1);
		else
		{
			int nextv;
			if(t[v].next.get(c)==null)
				nextv=-1;
			else
				nextv=t[v].next.get(c);
			return nextv!=-1?new position(nextv, leng(nextv)-1, pos.dep+1): new position(-1, -1, -1);
		}
	}
	position fast_go_down(int v, int l, int r)
	{
		if(l==r)
			return new position(v, 0, t[v].dep);
		while(true)
		{
			v=t[v].next.get(s[l]);
			if(leng(v)>=(r-l))
				return new position(v, leng(v)-(r-l), t[v].dep-leng(v)+(r-l));
			l+=leng(v);
		}
	}
	int link(int v)
	{
		if(t[v].link==-1)
		{
			int x=0;
			if(t[v].par==0)
				x=1;
			t[v].link=split_edge(fast_go_down(link(t[v].par), t[v].l+x, t[v].r));
		}
		return t[v].link;
	}
	position add_char_to_tree(position pos, int i)
	{
		while(true)
		{
			position npos=read_char(pos, s[i]);
			if(npos.V!=-1)
				return npos;
			int mid=split_edge(pos);
			int leaf=add_edge_to_parent(i, nmax, mid);
			suffixes.addLast(leaf);
			int nmid=link(mid);
			pos=new position(nmid, 0, t[nmid].dep);
			if(mid==0)
				return pos;
		}
	}
	void make_tree()
	{
		szt=0;
		root=new node(-1, -1, -1, 0);
		root.link=0;
		t[szt++]=root;
		pos=new position(0, 0, 0);
	}
	void add_char(char c)
	{
		s[tail++]=c;
		pos=add_char_to_tree(pos, tail-1);
	}
	position position_link(position pos)
	{
		int x=0;
		int v=pos.V;
		int l=t[v].l;
		int r=t[v].r-pos.L;
		if(t[v].par==0)
			x=1;
		position ans=fast_go_down(link(t[v].par), l+x, r);
		return ans;
	}
	public static void main(String args[])
	{
		Main ob=new Main();
		ob.solver();
	}
	void solver()
	{
		try{
		BufferedReader obj=new BufferedReader(new InputStreamReader(System.in));
		Scanner in=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		String s;
		i=2;nn=1;ii=2;nnn=1;
		texto[1]='$';
		texte[1]='$';
		s=in.next();
		n=in.nextInt();
		len=s.length();
		int ans=0;
		make_tree();
		for(int k=0;k<len;++k)
		{
			char ch=s.charAt(k);
			addLetterodd(ch);
			addLettereven(ch);
			add_char(ch);
			int rr=2*radodd[i]+1;
			int ss=2*radeven[ii];
			int p=suffixes.getLast();
			int cnt=0;
			while(true)
			{
				if(p==-1)
					break;
				if(t[p].r==nmax)
					cnt+=(k+1-t[p].l);
				else
					cnt+=t[p].r-t[p].l;
				p=t[p].par;
			}
			rr=Math.max(rr, ss);
			if(rr>=cnt)
				++ans;
		}
		System.out.println(answer(n, ans));
		}catch(Exception e){};
	}
	void addLetterodd(char c)
	{
		int s=i-radodd[i];
		texto[nn+1]=c;
		while(i+radodd[i]<=nn)
		{
			radodd[i]=Math.min(radodd[s+nn-i], nn-i);
			if(i+radodd[i]==nn && texto[i-radodd[i]-1]==c)
			{
				radodd[i]+=1;
				break;
			}
			i+=1;
		}
		nn+=1;
	}
	void addLettereven(char c)
	{
		int s=ii-radeven[ii]+1;
		texte[nnn+1]=c;
		while(ii+radeven[ii]<=nnn)
		{
			radeven[ii]=Math.min(radeven[s+nnn-ii-1], nnn-ii);
			if(ii+radeven[ii]==nnn && texte[ii-radeven[ii]-1+1]==c)
			{
				radeven[ii]+=1;
				break;
			}
			ii+=1;
		}
		nnn+=1;
	}
	BigInteger answer(int n, int a)
	{
		BigInteger ans=new BigInteger("0");
		if(n%2==0)
		{
			for(int d=1;d<=n;++d)
			{
				if(n%d==0)
				{
					ans=ans.add(new BigInteger(String.valueOf(phi[d])).multiply(new BigInteger(String.valueOf(a)).pow(n/d)));					
				}
			}
			return ans.add(new BigInteger(String.valueOf(n/2)).multiply(new BigInteger(String.valueOf(1+a))).multiply(new BigInteger(String.valueOf(a)).pow(n/2))).divide(new BigInteger(String.valueOf(2*n)));
		}
		else
		{
			for(int d=1;d<=n;++d)
			{
				if(n%d==0)
				{
					ans=ans.add(new BigInteger(String.valueOf(phi[d])).multiply(new BigInteger(String.valueOf(a)).pow(n/d)));					
				}
			}
			return ans.add(new BigInteger(String.valueOf(n)).multiply(new BigInteger(String.valueOf(a)).pow((n+1)/2))).divide(new BigInteger(String.valueOf(2*n)));
		}
	}
}
class node
{
	int l, r, par, link, dep, idx;
	HashMap<Character, Integer> next=new HashMap<Character, Integer>();
	node()
	{
		l=r=par=dep=0;
		link=-1;idx=-1;
	}
	node(int l, int r, int par, int dep)
	{
		this.l=l;
		this.r=r;
		this.par=par;
		this.dep=dep;
		link=-1;
		idx=-1;
	}
}
class position
{
	int V, L, dep;
	position()
	{
		V=L=dep=0;
	}
	position(int V, int L, int dep)
	{
		this.V=V;
		this.L=L;
		this.dep=dep;
	}
}