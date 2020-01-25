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
            this.components = new System.ComponentModel.Container();
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
            this.button1 = new System.Windows.Forms.Button();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.SearchByAttribute = new System.Windows.Forms.TextBox();
            this.EditName = new System.Windows.Forms.TextBox();
            this.EditAtt = new System.Windows.Forms.TextBox();
            this.SaveEdit = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.Search = new System.Windows.Forms.Button();
            this.labelEditTEXT = new System.Windows.Forms.Label();
            this.labelEditAttribute = new System.Windows.Forms.Label();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.ImagesList = new System.Windows.Forms.ComboBox();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.LoadedImage)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(963, 24);
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
            this.toolTip1.SetToolTip(this.WeaponsToSearchBox, "Write Weapon Name. \r\nNote: You may use the list below as guidance. \r\nJust don\'t i" +
        "nclude the .xml at the end.\r\n");
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
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(12, 537);
            this.button1.Margin = new System.Windows.Forms.Padding(2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(110, 67);
            this.button1.TabIndex = 17;
            this.button1.Text = "SORT";
            this.toolTip1.SetToolTip(this.button1, "Sorts by attribute");
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // SearchByAttribute
            // 
            this.SearchByAttribute.Location = new System.Drawing.Point(151, 565);
            this.SearchByAttribute.Margin = new System.Windows.Forms.Padding(2);
            this.SearchByAttribute.Multiline = true;
            this.SearchByAttribute.Name = "SearchByAttribute";
            this.SearchByAttribute.Size = new System.Drawing.Size(84, 39);
            this.SearchByAttribute.TabIndex = 20;
            this.toolTip1.SetToolTip(this.SearchByAttribute, "Enter Attribute To Search...");
            // 
            // EditName
            // 
            this.EditName.Location = new System.Drawing.Point(310, 110);
            this.EditName.Margin = new System.Windows.Forms.Padding(2);
            this.EditName.Name = "EditName";
            this.EditName.Size = new System.Drawing.Size(125, 20);
            this.EditName.TabIndex = 24;
            this.EditName.Text = "Enter new name...";
            this.toolTip1.SetToolTip(this.EditName, "Enter New Name");
            // 
            // EditAtt
            // 
            this.EditAtt.Location = new System.Drawing.Point(310, 144);
            this.EditAtt.Margin = new System.Windows.Forms.Padding(2);
            this.EditAtt.Name = "EditAtt";
            this.EditAtt.Size = new System.Drawing.Size(125, 20);
            this.EditAtt.TabIndex = 25;
            this.EditAtt.Text = "Enter new attribute";
            this.toolTip1.SetToolTip(this.EditAtt, "Enter New Attribute\r\nNote: Attribute can only equal 10 or 20 or 30.");
            // 
            // SaveEdit
            // 
            this.SaveEdit.Location = new System.Drawing.Point(90, 120);
            this.SaveEdit.Margin = new System.Windows.Forms.Padding(2);
            this.SaveEdit.Name = "SaveEdit";
            this.SaveEdit.Size = new System.Drawing.Size(56, 19);
            this.SaveEdit.TabIndex = 26;
            this.SaveEdit.Text = "Save";
            this.toolTip1.SetToolTip(this.SaveEdit, "Save Changes on selected weapon");
            this.SaveEdit.UseVisualStyleBackColor = true;
            this.SaveEdit.Click += new System.EventHandler(this.SaveEdit_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.ImagesList);
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.SaveEdit);
            this.panel1.Location = new System.Drawing.Point(238, 103);
            this.panel1.Margin = new System.Windows.Forms.Padding(2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(201, 143);
            this.panel1.TabIndex = 27;
            this.toolTip1.SetToolTip(this.panel1, "Weapon Editor");
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.label6.Location = new System.Drawing.Point(2, 80);
            this.label6.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(70, 13);
            this.label6.TabIndex = 31;
            this.label6.Text = "Image Saved";
            // 
            // Search
            // 
            this.Search.Location = new System.Drawing.Point(151, 537);
            this.Search.Margin = new System.Windows.Forms.Padding(2);
            this.Search.Name = "Search";
            this.Search.Size = new System.Drawing.Size(83, 32);
            this.Search.TabIndex = 19;
            this.Search.Text = "Search";
            this.Search.UseVisualStyleBackColor = true;
            this.Search.Click += new System.EventHandler(this.Search_Click);
            // 
            // labelEditTEXT
            // 
            this.labelEditTEXT.AutoSize = true;
            this.labelEditTEXT.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.labelEditTEXT.Location = new System.Drawing.Point(240, 110);
            this.labelEditTEXT.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelEditTEXT.Name = "labelEditTEXT";
            this.labelEditTEXT.Size = new System.Drawing.Size(56, 13);
            this.labelEditTEXT.TabIndex = 22;
            this.labelEditTEXT.Text = "Edit Name";
            // 
            // labelEditAttribute
            // 
            this.labelEditAttribute.AutoSize = true;
            this.labelEditAttribute.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.labelEditAttribute.Location = new System.Drawing.Point(240, 144);
            this.labelEditAttribute.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.labelEditAttribute.Name = "labelEditAttribute";
            this.labelEditAttribute.Size = new System.Drawing.Size(67, 13);
            this.labelEditAttribute.TabIndex = 23;
            this.labelEditAttribute.Text = "Edit Attribute";
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(12, 108);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(202, 95);
            this.listBox1.TabIndex = 29;
            this.toolTip1.SetToolTip(this.listBox1, "List Of Weapons Loaded in");
            this.listBox1.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            this.listBox1.MouseEnter += new System.EventHandler(this.listBox1_MouseEnter_1);
            // 
            // ImagesList
            // 
            this.ImagesList.FormattingEnabled = true;
            this.ImagesList.Location = new System.Drawing.Point(77, 77);
            this.ImagesList.Name = "ImagesList";
            this.ImagesList.Size = new System.Drawing.Size(119, 21);
            this.ImagesList.TabIndex = 34;
            this.ImagesList.Text = "Image List";
            // 
            // MainScreen
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(963, 609);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.labelEditTEXT);
            this.Controls.Add(this.labelEditAttribute);
            this.Controls.Add(this.EditName);
            this.Controls.Add(this.EditAtt);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.SearchByAttribute);
            this.Controls.Add(this.Search);
            this.Controls.Add(this.button1);
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
            this.Name = "MainScreen";
            this.Text = "Form2";
            this.Activated += new System.EventHandler(this.MainScreen_Activated);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.LoadedImage)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
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
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.Button Search;
        private System.Windows.Forms.TextBox SearchByAttribute;
        private System.Windows.Forms.Label labelEditTEXT;
        private System.Windows.Forms.Label labelEditAttribute;
        private System.Windows.Forms.TextBox EditName;
        private System.Windows.Forms.TextBox EditAtt;
        private System.Windows.Forms.Button SaveEdit;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox ImagesList;
    }
}