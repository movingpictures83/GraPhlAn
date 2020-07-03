# GraPhlAn
# Language: C++
# Input: TXT
# Output: PREFIX
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: GraPhlAn 0.9.7

Annotate and create an image of a phylogenetic tree using GraPhlAn (Asnicar et al, 2015).

The plugin expects as input a TXT file of keyword-value pairs, for the following parameters:
tree: XML file of phylogenetic tree to visualize
annotations: TXT file of annotations (optional, if not provided will just visualize the tree)

The tree, annotated or not annotated, will be output to an image file with the output prefix
concatenated with ".png".
If annotation is selected, an XML file will also be output with the modified tree.  This will
be saved as "prefix.annot.xml".

Note: The plugin depends on the central graphlan.py Python script to be in your system PATH.
