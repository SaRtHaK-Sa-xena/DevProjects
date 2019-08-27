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
            this.MainListOfWeapons = new System.Windows.Forms.ListBox();
            this.WeaponsToSearchBox = new System.Windows.Forms.TextBox();
            this.MainListBoxOfWeapons = new System.Windows.Forms.ListBox();
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
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(976, 24);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.newFileToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // newFileToolStripMenuItem
            // 
            this.newFileToolStripMenuItem.Name = "newFileToolStripMenuItem";
            this.newFileToolStripMenuItem.Size = new System.Drawing.Size(182, 22);
            this.newFileToolStripMenuItem.Text = "Create New Weapon";
            this.newFileToolStripMenuItem.Click += new System.EventHandler(this.newFileToolStripMenuItem_Click);
            // 
            // MainListOfWeapons
            // 
            this.MainListOfWeapons.FormattingEnabled = true;
            this.MainListOfWeapons.Items.AddRange(new object[] {
            "Weapon Sample 1",
            "Weapon Sample 2"});
            this.MainListOfWeapons.Location = new System.Drawing.Point(12, 89);
            this.MainListOfWeapons.Name = "MainListOfWeapons";
            this.MainListOfWeapons.Size = new System.Drawing.Size(310, 43);
            this.MainListOfWeapons.TabIndex = 3;
            // 
            // WeaponsToSearchBox
            // 
            this.WeaponsToSearchBox.BackColor = System.Drawing.Color.Gold;
            this.WeaponsToSearchBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.WeaponsToSearchBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WeaponsToSearchBox.Location = new System.Drawing.Point(12, 53);
            this.WeaponsToSearchBox.Name = "WeaponsToSearchBox";
            this.WeaponsToSearchBox.Size = new System.Drawing.Size(309, 30);
            this.WeaponsToSearchBox.TabIndex = 4;
            this.WeaponsToSearchBox.Text = "WEAPONS";
            // 
            // MainListBoxOfWeapons
            // 
            this.MainListBoxOfWeapons.FormattingEnabled = true;
            this.MainListBoxOfWeapons.Location = new System.Drawing.Point(13, 139);
            this.MainListBoxOfWeapons.Name = "MainListBoxOfWeapons";
            this.MainListBoxOfWeapons.Size = new System.Drawing.Size(309, 95);
            this.MainListBoxOfWeapons.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(13, 275);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(215, 25);
            this.label1.TabIndex = 6;
            this.label1.Text = "Loaded Weapon Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(13, 320);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(165, 25);
            this.label2.TabIndex = 7;
            this.label2.Text = "Loaded Attributes";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(184, 320);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(0, 25);
            this.label3.TabIndex = 8;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(234, 275);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(0, 25);
            this.label4.TabIndex = 9;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(47, 504);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(137, 25);
            this.label5.TabIndex = 10;
            this.label5.Text = "Loaded Image";
            // 
            // LoadedImage
            // 
            this.LoadedImage.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.LoadedImage.Location = new System.Drawing.Point(18, 360);
            this.LoadedImage.Name = "LoadedImage";
            this.LoadedImage.Size = new System.Drawing.Size(216, 141);
            this.LoadedImage.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.LoadedImage.TabIndex = 11;
            this.LoadedImage.TabStop = false;
            // 
            // LoadedAttributeTEXT
            // 
            this.LoadedAttributeTEXT.Location = new System.Drawing.Point(239, 318);
            this.LoadedAttributeTEXT.Multiline = true;
            this.LoadedAttributeTEXT.Name = "LoadedAttributeTEXT";
            this.LoadedAttributeTEXT.Size = new System.Drawing.Size(120, 36);
            this.LoadedAttributeTEXT.TabIndex = 13;
            // 
            // LoadedWeaponTEXT
            // 
            this.LoadedWeaponTEXT.Location = new System.Drawing.Point(240, 275);
            this.LoadedWeaponTEXT.Multiline = true;
            this.LoadedWeaponTEXT.Name = "LoadedWeaponTEXT";
            this.LoadedWeaponTEXT.Size = new System.Drawing.Size(120, 36);
            this.LoadedWeaponTEXT.TabIndex = 14;
            // 
            // LoadWeaponButton
            // 
            this.LoadWeaponButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LoadWeaponButton.Location = new System.Drawing.Point(12, 532);
            this.LoadWeaponButton.Name = "LoadWeaponButton";
            this.LoadWeaponButton.Size = new System.Drawing.Size(238, 67);
            this.LoadWeaponButton.TabIndex = 15;
            this.LoadWeaponButton.Text = "Load Weapon";
            this.LoadWeaponButton.UseVisualStyleBackColor = true;
            this.LoadWeaponButton.Click += new System.EventHandler(this.LoadWeaponButton_Click);
            // 
            // MainScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(976, 611);
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
            this.Controls.Add(this.MainListBoxOfWeapons);
            this.Controls.Add(this.WeaponsToSearchBox);
            this.Controls.Add(this.MainListOfWeapons);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
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
        private System.Windows.Forms.ListBox MainListOfWeapons;
        private System.Windows.Forms.TextBox WeaponsToSearchBox;
        private System.Windows.Forms.ListBox MainListBoxOfWeapons;
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