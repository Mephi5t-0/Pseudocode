/* Prim算法生成最小生成树 */
#define MAXVEX 9
#define INFINITY 32767
void MiniSpanTree_Prim(MGraph G)
{
    int min, i, j, k;
    int adjvex[MAXVEX];  /* 保存相关顶点下标 */
    int lowcost[MAXVEX]; /* 保存相关顶点之间的权值 */
    lowcost[0] = 0;      /* 初始化第一个权值为0，即v_0加入生成树,lowcost的值为0，意味着此下标的顶点已经加入生成树 */
    adjvex[0] = 0;       /* 初始化第一个顶点下标为0 */
    for (i = 1; i < G.numvertexes; i++)
    {
        lowcost[i] = G.arc[0][i]; /* 将v_0顶点与之有边的权值存入数组 */
        adjvex[i] = 0;            /* 初始化都为v_0下标 */
    }
    for (i = 1; i < G.numVertexes; i++)
    {
        min = INFINITY;
        j = 1;
        k = 0;
        while (j < G.numVertexes) /* 循环全部顶点 */
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                /* 如果权值不为0，且权值小于min */
                min = lowcost[j]; /* 则使当前权值为最小值 */
                k = j;            /* 将当前最小值的下标存入k */
            }
            j++;
        }
        printf("(%d,%d)", adjvex[k], k); /* 打印当前顶点边中权值最小边 */
        lowcost[k] = 0;                  /* 将当前顶点的权值设置为0,表示此顶点已完成任务 */
        for (j = 1; j < G.numVertexes; j++)
        {
            /* 循环所有顶点 */
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                /* 若下标为K的顶点的各边权值，小于此前这些顶点未被加入生成树权值 */
                lowcost[j] = G.arc[k][j]; /* 将较小权值存入lowcost */
                adjvex[j] = k;            /* 将下标为k的顶点存入adjvex */
            }
        }
    }
}