/*
 * BedgraphWrite.cpp
 *
 *  Created on: Jun 24, 2020
 *      Author: rohan
 */

#include "BITOps.h"
#include "BedgraphWrite.h"

using namespace std;

//Write the bedgraph output as a compressed bedgraph file with 2 decimal fixed precision. Note: Only requires tree1.
void writeBedgraphInternal(treesVec& tree, string bedgraph_filename)
{
	ogzstream bedgraph_file(bedgraph_filename.c_str());

	outlog << "Writing bedgraph to " << bedgraph_filename << "\n";

	bedgraph_file << fixed << setprecision(2);

	for (unsigned int chromindex = 0; chromindex < tree.size(); chromindex++)
	{
		string chromname = counter_to_chrom[chromindex];
		int chromlength = counter_to_length[chromindex];

		int storedstart = 1;
		float storedval = treeSum(tree[chromindex], 1);

		for (int i = 2; i <= chromlength; i++)
		{
			float newval = treeSum(tree[chromindex], i);
			if (newval < 1e-2) { newval = 0; }
			if (storedval == newval)
			{
				continue;
			}
			else
			{
				bedgraph_file << chromname << "\t" << storedstart << "\t" << i << "\t" << storedval << "\n";
				storedstart = i;
				storedval = newval;
			}
		}

		if (storedstart != chromlength)
		{
			bedgraph_file << chromname << "\t" << storedstart << "\t" << chromlength << "\t" << storedval << "\n";
		}
	}

	bedgraph_file.close();
}

void writeBedgraphOutput(string file_prefix)
{
	if (stranded)
	{
		string file_pos = file_prefix + "_plus-strand.bedgraph.gz";
		string file_neg = file_prefix + "_minus-strand.bedgraph.gz";
		writeBedgraphInternal(tree1, file_pos);
		writeBedgraphInternal(tree1neg, file_neg);
	}
	else
	{
		string filename = file_prefix + ".bedgraph.gz";
		writeBedgraphInternal(tree1, filename);
	}
}
