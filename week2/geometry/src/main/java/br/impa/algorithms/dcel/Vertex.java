package br.impa.algorithms.dcel;

public class Vertex {
    private Point point;
    private HalfEdge leaving;

    public Vertex() {
        this.point = null;
        this.leaving = null;
    }

    public void setPoint(Point point){this.point = point;}
    public Point getPoint(){return this.point;}

    public void setLeaving(HalfEdge leaving){this.leaving = leaving;}
    public HalfEdge getLeaving(){return this.leaving;}

}
