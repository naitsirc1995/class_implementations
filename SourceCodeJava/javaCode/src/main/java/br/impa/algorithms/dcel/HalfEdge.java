package br.impa.algorithms.dcel;

public class HalfEdge {
    private Vertex origin;
    private Face face;
    private HalfEdge twin;
    private HalfEdge next;

    public HalfEdge() {
        this.origin = null;
        this.face = null;
        this.twin = null;
        this.next = null;
    }
    public void setOrigin(Vertex vertex) {this.origin = vertex;}
    public Vertex getOrigin(){return this.origin;}

    public void setFace(Face face){this.face = face;}
    public Face getFace(){return this.face;}

    public void setTwin(HalfEdge twin){this.twin = twin;}
    public HalfEdge getTwin(){return this.twin;}

    public void setNext(HalfEdge next){this.next = next;}
    public HalfEdge getNext(){return this.next;}


}
