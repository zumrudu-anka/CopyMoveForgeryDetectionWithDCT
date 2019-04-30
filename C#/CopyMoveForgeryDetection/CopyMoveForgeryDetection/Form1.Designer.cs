namespace CopyMoveForgeryDetection
{
    partial class Form1
    {
        /// <summary>
        ///Gerekli tasarımcı değişkeni.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///Kullanılan tüm kaynakları temizleyin.
        /// </summary>
        ///<param name="disposing">yönetilen kaynaklar dispose edilmeliyse doğru; aksi halde yanlış.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer üretilen kod

        /// <summary>
        /// Tasarımcı desteği için gerekli metot - bu metodun 
        ///içeriğini kod düzenleyici ile değiştirmeyin.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.operationsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.showIntensityToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dCTToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tryToDetectForgeryToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.Acceptance_Limit_Numeric = new System.Windows.Forms.NumericUpDown();
            this.Th_Value_Between_Blocks_Numeric = new System.Windows.Forms.NumericUpDown();
            this.DosyaSecDialog = new System.Windows.Forms.OpenFileDialog();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Acceptance_Limit_Numeric)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Th_Value_Between_Blocks_Numeric)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem,
            this.operationsToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(713, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // operationsToolStripMenuItem
            // 
            this.operationsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.showIntensityToolStripMenuItem,
            this.dCTToolStripMenuItem,
            this.tryToDetectForgeryToolStripMenuItem});
            this.operationsToolStripMenuItem.Name = "operationsToolStripMenuItem";
            this.operationsToolStripMenuItem.Size = new System.Drawing.Size(77, 20);
            this.operationsToolStripMenuItem.Text = "Operations";
            // 
            // openToolStripMenuItem
            // 
            this.openToolStripMenuItem.Name = "openToolStripMenuItem";
            this.openToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.openToolStripMenuItem.Text = "Open";
            this.openToolStripMenuItem.Click += new System.EventHandler(this.openToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // showIntensityToolStripMenuItem
            // 
            this.showIntensityToolStripMenuItem.Name = "showIntensityToolStripMenuItem";
            this.showIntensityToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.showIntensityToolStripMenuItem.Text = "Show Intensity";
            this.showIntensityToolStripMenuItem.Click += new System.EventHandler(this.showIntensityToolStripMenuItem_Click);
            // 
            // dCTToolStripMenuItem
            // 
            this.dCTToolStripMenuItem.Name = "dCTToolStripMenuItem";
            this.dCTToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.dCTToolStripMenuItem.Text = "DCT";
            this.dCTToolStripMenuItem.Click += new System.EventHandler(this.dCTToolStripMenuItem_Click);
            // 
            // tryToDetectForgeryToolStripMenuItem
            // 
            this.tryToDetectForgeryToolStripMenuItem.Name = "tryToDetectForgeryToolStripMenuItem";
            this.tryToDetectForgeryToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.tryToDetectForgeryToolStripMenuItem.Text = "Try To Detect Forgery";
            this.tryToDetectForgeryToolStripMenuItem.Click += new System.EventHandler(this.tryToDetectForgeryToolStripMenuItem_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(12, 39);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(320, 240);
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Location = new System.Drawing.Point(369, 39);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(320, 240);
            this.pictureBox2.TabIndex = 2;
            this.pictureBox2.TabStop = false;
            // 
            // progressBar1
            // 
            this.progressBar1.BackColor = System.Drawing.Color.DarkSlateGray;
            this.progressBar1.Cursor = System.Windows.Forms.Cursors.WaitCursor;
            this.progressBar1.ForeColor = System.Drawing.Color.DarkSlateGray;
            this.progressBar1.Location = new System.Drawing.Point(12, 285);
            this.progressBar1.MarqueeAnimationSpeed = 10;
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(677, 29);
            this.progressBar1.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.progressBar1.TabIndex = 6;
            this.progressBar1.Visible = false;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Monotype Corsiva", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label2.Location = new System.Drawing.Point(281, 377);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(336, 18);
            this.label2.TabIndex = 10;
            this.label2.Text = "Acceptance Limit Which Count of Similar Blocks:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Monotype Corsiva", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label1.Location = new System.Drawing.Point(281, 415);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(359, 18);
            this.label1.TabIndex = 11;
            this.label1.Text = "Threshold Value Which Between Blocks to Compare:";
            // 
            // Acceptance_Limit_Numeric
            // 
            this.Acceptance_Limit_Numeric.Font = new System.Drawing.Font("Monotype Corsiva", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.Acceptance_Limit_Numeric.Location = new System.Drawing.Point(646, 375);
            this.Acceptance_Limit_Numeric.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.Acceptance_Limit_Numeric.Name = "Acceptance_Limit_Numeric";
            this.Acceptance_Limit_Numeric.Size = new System.Drawing.Size(43, 25);
            this.Acceptance_Limit_Numeric.TabIndex = 12;
            this.Acceptance_Limit_Numeric.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.Acceptance_Limit_Numeric.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // Th_Value_Between_Blocks_Numeric
            // 
            this.Th_Value_Between_Blocks_Numeric.Font = new System.Drawing.Font("Monotype Corsiva", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.Th_Value_Between_Blocks_Numeric.Location = new System.Drawing.Point(646, 413);
            this.Th_Value_Between_Blocks_Numeric.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.Th_Value_Between_Blocks_Numeric.Name = "Th_Value_Between_Blocks_Numeric";
            this.Th_Value_Between_Blocks_Numeric.Size = new System.Drawing.Size(43, 25);
            this.Th_Value_Between_Blocks_Numeric.TabIndex = 13;
            this.Th_Value_Between_Blocks_Numeric.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.Th_Value_Between_Blocks_Numeric.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // DosyaSecDialog
            // 
            this.DosyaSecDialog.FileName = "DosyaSecDialog";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(713, 450);
            this.Controls.Add(this.Th_Value_Between_Blocks_Numeric);
            this.Controls.Add(this.Acceptance_Limit_Numeric);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Acceptance_Limit_Numeric)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Th_Value_Between_Blocks_Numeric)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem operationsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem showIntensityToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dCTToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tryToDetectForgeryToolStripMenuItem;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown Acceptance_Limit_Numeric;
        private System.Windows.Forms.NumericUpDown Th_Value_Between_Blocks_Numeric;
        private System.Windows.Forms.OpenFileDialog DosyaSecDialog;
    }
}

