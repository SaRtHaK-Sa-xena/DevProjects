namespace WeaponsCreaterTool
{
    partial class MainScreen
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.newFileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.WeaponsToSearchBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.LoadedImage = new System.Windows.Forms.PictureBox();
            this.LoadedAttributeTEXT = new System.Windows.Forms.TextBox();
            this.LoadedWeaponTEXT = new System.Windows.Forms.TextBox();
            this.LoadWeaponButton = new System.Windows.Forms.Button();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.LoadedImage)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Padding = new System.Windows.Forms.Padding(8, 2, 0, 2);
            this.menuStrip1.Size = new System.Drawing.Size(1284, 28);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newFileToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(44, 24);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newFileToolStripMenuItem
            // 
            this.newFileToolStripMenuItem.Name = "newFileToolStripMenuItem";
            this.newFileToolStripMenuItem.Size = new System.Drawing.Size(220, 26);
            this.newFileToolStripMenuItem.Text = "Create New Weapon";
            this.newFileToolStripMenuItem.Click += new System.EventHandler(this.newFileToolStripMenuItem_Click);
            // 
            // WeaponsToSearchBox
            // 
            this.WeaponsToSearchBox.BackColor = System.Drawing.Color.Gold;
            this.WeaponsToSearchBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.WeaponsToSearchBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WeaponsToSearchBox.Location = new System.Drawing.Point(16, 65);
            this.WeaponsToSearchBox.Margin = new System.Windows.Forms.Padding(4);
            this.WeaponsToSearchBox.Name = "WeaponsToSearchBox";
            this.WeaponsToSearchBox.Size = new System.Drawing.Size(411, 36);
            this.WeaponsToSearchBox.TabIndex = 4;
            this.WeaponsToSearchBox.Text = "WEAPONS";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(17, 338);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(273, 29);
            this.label1.TabIndex = 6;
            this.label1.Text = "Loaded Weapon Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(17, 394);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(211, 29);
            this.label2.TabIndex = 7;
            this.label2.Text = "Loaded Attributes";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(245, 394);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(0, 29);
            this.label3.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(312, 338);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(0, 29);
            this.label4.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(63, 620);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(174, 29);
            this.label5.TabIndex = 10;
            this.label5.Text = "Loaded Image";
            // 
            // LoadedImage
            // 
            this.LoadedImage.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.LoadedImage.Location = new System.Drawing.Point(24, 443);
            this.LoadedImage.Margin = new System.Windows.Forms.Padding(4);
            this.LoadedImage.Name = "LoadedImage";
            this.LoadedImage.Size = new System.Drawing.Size(287, 173);
            this.LoadedImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.LoadedImage.TabIndex = 11;
            this.LoadedImage.TabStop = false;
            // 
            // LoadedAttributeTEXT
            // 
            this.LoadedAttributeTEXT.Location = new System.Drawing.Point(319, 391);
            this.LoadedAttributeTEXT.Margin = new System.Windows.Forms.Padding(4);
            this.LoadedAttributeTEXT.Multiline = true;
            this.LoadedAttributeTEXT.Name = "LoadedAttributeTEXT";
            this.LoadedAttributeTEXT.Size = new System.Drawing.Size(159, 43);
            this.LoadedAttributeTEXT.TabIndex = 13;
            // 
            // LoadedWeaponTEXT
            // 
            this.LoadedWeaponTEXT.Location = new System.Drawing.Point(320, 338);
            this.LoadedWeaponTEXT.Margin = new System.Windows.Forms.Padding(4);
            this.LoadedWeaponTEXT.Multiline = true;
            this.LoadedWeaponTEXT.Name = "LoadedWeaponTEXT";
            this.LoadedWeaponTEXT.Size = new System.Drawing.Size(159, 43);
            this.LoadedWeaponTEXT.TabIndex = 14;
            // 
            // LoadWeaponButton
            // 
            this.LoadWeaponButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LoadWeaponButton.Location = new System.Drawing.Point(16, 655);
            this.LoadWeaponButton.Margin = new System.Windows.Forms.Padding(4);
            this.LoadWeaponButton.Name = "LoadWeaponButton";
            this.LoadWeaponButton.Size = new System.Drawing.Size(317, 82);
            this.LoadWeaponButton.TabIndex = 15;
            this.LoadWeaponButton.Text = "Load Weapon";
            this.LoadWeaponButton.UseVisualStyleBackColor = true;
            this.LoadWeaponButton.Click += new System.EventHandler(this.LoadWeaponButton_Click);
            // 
            // MainScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(1284, 752);
            this.Controls.Add(this.LoadWeaponButton);
            this.Controls.Add(this.LoadedWeaponTEXT);
            this.Controls.Add(this.LoadedAttributeTEXT);
            this.Controls.Add(this.LoadedImage);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.WeaponsToSearchBox);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "MainScreen";
            this.Text = "Form2";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.LoadedImage)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem newFileToolStripMenuItem;
        private System.Windows.Forms.TextBox WeaponsToSearchBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.PictureBox LoadedImage;
        private System.Windows.Forms.TextBox LoadedAttributeTEXT;
        private System.Windows.Forms.TextBox LoadedWeaponTEXT;
        private System.Windows.Forms.Button LoadWeaponButton;
    }
}