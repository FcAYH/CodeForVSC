using System.Runtime.Serialization;
using System.Transactions;
/*
 * @lc app=leetcode.cn id=690 lang=csharp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public IList<int> subordinates;
}
*/

class Solution
{
    IList<int> index = new List<int>();
    int dfs(IList<Employee> employees, int id)
    {
        int val = employees[index[id]].importance;

        if (employees[index[id]].subordinates != null)
        {
            foreach (int sub in employees[index[id]].subordinates)
            {
                val += dfs(employees, sub);
            }
        }
        return val;
    }
    public int GetImportance(IList<Employee> employees, int id)
    {
        int val = 0;

        employees = employees.OrderBy(o => o.id).ToList();

        int decrease = (employees[0].id - 1);

        int cnt = 0;
        for (int i = 0; i < employees.Count; i++)
        {
            employees[i].id -= decrease;

            for (int j = 0; j < employees[i].subordinates.Count; j++)
                employees[i].subordinates[j] -= decrease;

            while (index.Count < employees[i].id)
                index.Add(0);
            index.Add(cnt++);
        }

        // foreach (int i in index)
        // {
        //     Console.WriteLine("this is :" + i.ToString());
        // }
        //Console.WriteLine(index.Count);

        val = dfs(employees, id - decrease);
        // foreach (Employee emp in employees)
        // {
        //     if (emp.id == id)
        //         val = dfs(emp);
        // }

        return val;
    }
}
// @lc code=end

//[[1, 5, [2, 3]], [2, 3, []], [3, 3, []]]\n1
//[[2,5,[]]]\n2
