package br.impa.algorithms.dcel;

public class Face {
    private HalfEdge edge;

    public Face(){
        this.edge = null;
    }

    public void setEdge(HalfEdge edge){this.edge = edge;}
    public HalfEdge getEdge(){return this.edge;}
}
