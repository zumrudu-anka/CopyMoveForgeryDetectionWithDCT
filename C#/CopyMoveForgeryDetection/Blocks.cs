using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CopyMoveForgeryDetection
{
    class Blocks
    {
        private int row, column;
        private int[] diagonalorder;
        public void SetDiagonalOrder(int[] thresholded_diago_array, int r, int c)
        {
            diagonalorder = new int[15];
            for (int i = 0; i < 15; i++)
            {
                diagonalorder[i] = thresholded_diago_array[i];
                row = r;
                column = c;
            }
        }

        public int[] GetDiagonalOrder()
        {
            return diagonalorder;
        }

        public int GetRow()
        {
            return row;
        }
        public int GetColumn()
        {
            return column;
        }

    }
}
