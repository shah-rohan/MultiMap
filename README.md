# MultiMap: Iterative Bayesian Analysis of Ambiguously Mapped Reads in ChIP-seq

This tool is designed to analyze ambiguously mapped reads from paired-end short-read next-generation sequencing by using the alignment scores and the distribution of mapped reads genome-wide to iteratively reweight and refine the weights assigned to each mapped location of each read. This tool is primarily intended for and validated on ChIP-seq and simulated ChIP-seq data; however, in principle, this tool can be used for DNA-seq and other selected NGS applications more broadly. Furthermore, this tool was primarily devised to analyze ICeChIP-seq data; however, this tool does not itself perform ICeChIP-specific analyses and can therefore be used more broadly for ChIP-seq.

There are two components to the tool presented here: the MultiMapPrep bash script and the MultiMap compiled binary. The MultiMapPrep script serves to align the fastq files to the genome, filter the output file, and parse it into a BED file that can be used with the MultiMap binary. The MultiMap binary is a compiled program written in C++ to analyze the alignment BED file produced by MultiMapPrep with the iterative Bayesian algorithm and produce a BEDGRAPH file of map weights across the genome, which can be treated as the weighted genome coverage BEDGRAPH file.

This tool is designed for use with Bowtie2.
