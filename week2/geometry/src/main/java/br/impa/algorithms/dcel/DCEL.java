package br.impa.algorithms.dcel;



import java.sql.SQLOutput;
import java.util.ArrayList;

public class DCEL {
    private ArrayList<HalfEdge> halfedges;

    public DCEL(ArrayList<Point> simplePolygonPoints) throws Exception {
        int simplePolygonSize = simplePolygonPoints.size();
        System.out.println("[info] simple-polygon vertices should be provided counterclockwise");
        System.out.println("[info] simple polygon with " + simplePolygonSize + " provided");
        if (simplePolygonPoints.size() < 3)
        {
            System.out.println("Invalid number of vertices for single polygon");
            return;
        }

        ArrayList<HalfEdge> tmpHalfEdges = new ArrayList<HalfEdge>();
        for (int i = 0; i < simplePolygonSize; i++){
            // First point information
            Point point1 = simplePolygonPoints.get(i);
            Point point2 = simplePolygonPoints.get((i+1)%simplePolygonSize);

            HalfEdge firstEdge = new HalfEdge();
            Vertex firstVertex = new Vertex();
            Face firstFace = new Face();

            HalfEdge firstTwinEdge = new HalfEdge();
            Vertex firstTwinVertex = new Vertex();

            // Setting the first face
            if (i == 0)
                firstFace.setEdge(firstEdge);
            else
                firstFace.setEdge(tmpHalfEdges.get(0));

            // Setting the first vertex
            firstVertex.setPoint(point1);
            firstVertex.setLeaving(firstEdge);

            // Setting the first twin vertex
            firstTwinVertex.setPoint(point2);
            firstTwinVertex.setLeaving(firstTwinEdge);

            // Setting the first vertex
            firstEdge.setOrigin(firstVertex);
            firstEdge.setFace(firstFace);
            firstEdge.setTwin(firstTwinEdge);

            // Setting the first Twin vertex
            firstTwinEdge.setOrigin(firstTwinVertex);
            firstTwinEdge.setTwin(firstEdge);

            // Setting first twin vertex
            tmpHalfEdges.add(firstEdge);
        }

        for (int i = 0; i < simplePolygonSize; i++){
            HalfEdge halfEdge = tmpHalfEdges.get(i);
            halfEdge.setNext(tmpHalfEdges.get((i+1)%simplePolygonSize));
        }

        for (int i = simplePolygonSize-1; i >= 0; i--){
            HalfEdge halfEdge = tmpHalfEdges.get(i);
            if (i!= 0){
                HalfEdge halfEdge1 = tmpHalfEdges.get(i-1);
                halfEdge.getTwin().setNext(halfEdge1.getTwin());
            } else {
                HalfEdge halfEdge1 = tmpHalfEdges.get(simplePolygonSize-1);
                halfEdge.getTwin().setNext(halfEdge1.getTwin());
            }
        }

        halfedges = new ArrayList<HalfEdge>();
        for (int i = 0 ; i < simplePolygonSize ; i++){
            halfedges.add(tmpHalfEdges.get(i));
            halfedges.add(tmpHalfEdges.get(i).getTwin());
        }

        tmpHalfEdges = null;
    }

    public ArrayList<HalfEdge> getHalfEdges(){return this.halfedges;}
}
