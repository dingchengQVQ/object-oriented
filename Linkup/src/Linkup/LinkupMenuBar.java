package Linkup;

import java.awt.Paint;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.TreeSet;

import javax.swing.AbstractButton;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.plaf.OptionPaneUI;

import Dialog.AboutJDialog;
import Dialog.ExitJDialog;
import Dialog.ParamJDialog;
import Dialog.RuleJDialog;
import Dialog.ScoreJDialog;
import tools.Param;
import tools.Student;

public class LinkupMenuBar extends JMenuBar {
	JMenuItem menuItemParam = new JMenuItem("��Ϸ����");
	JMenu menuItemBackground = new JMenu("���ñ���");
	JMenu menuItemChessIcon = new JMenu("��������");
	JMenuItem menuItemScore = new JMenuItem("�鿴�ɼ�");
	JMenuItem menuItemExit = new JMenuItem("�˳���Ϸ");
	JMenuItem menuItemRule = new JMenuItem("��Ϸ����");
	
	JMenuItem menuItemAbout = new JMenuItem("��Ϸ��Ȩ");

	LinkeUpMainFrame mainFrame;
	public LinkupMenuBar(LinkeUpMainFrame mainFrame) {
		this.mainFrame=mainFrame;
		
		this.init();
	}
	private void init() {
		
		JMenu menuSet = new JMenu("����");
		menuSet.add(menuItemParam);
		menuSet.addSeparator();
		menuSet.add(menuItemBackground);
		menuSet.addSeparator();
		menuSet.add(menuItemChessIcon);
		menuSet.addSeparator();
		menuSet.add(menuItemScore);
		menuSet.addSeparator();
		menuSet.add(menuItemExit);
		String[] arrIcon=new String[]{"ˮ��","ͼ��","�ɰ�","friends"};
		for (int i = 0; i < arrIcon.length; i++) {
			final JCheckBoxMenuItem jCheckBoxMenuItem = new JCheckBoxMenuItem(arrIcon[i]);
			menuItemChessIcon.add(jCheckBoxMenuItem);
			menuItemChessIcon.addSeparator();
			jCheckBoxMenuItem.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					String text = jCheckBoxMenuItem.getText();
					if("ˮ��".equals(text)){
						Param.chessImageIcon=Param.chessImage[0];
					}else if("ͼ��".equals(text)){
						Param.chessImageIcon=Param.chessImage[1];
					}else if("�ɰ�".equals(text)){
						Param.chessImageIcon=Param.chessImage[2];
					}else if("friends".equals(text)){
						Param.chessImageIcon=Param.chessImage[3];
					}
					mainFrame.repaint();
				}
			});
		}
		
		String[] arr = new String[]{"��ɫ���","����֮��","�̲�����","ˮī�໨","����ͷ�","��ɫ֮��"};
		ButtonGroup buttonGroup = new ButtonGroup();
		for (int i = 0; i < arr.length; i++) {
			final JCheckBoxMenuItem jCheckBoxMenuItem = new JCheckBoxMenuItem(arr[i]);
			
			menuItemBackground.add(jCheckBoxMenuItem);
			menuItemBackground.addSeparator();
			buttonGroup.add(jCheckBoxMenuItem);
			jCheckBoxMenuItem.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					String text = jCheckBoxMenuItem.getText();
					if("��ɫ���".equals(text)){
						Param.imageBackground=Param.imageBackgroundLSTK;
					}else if("����֮��".equals(text)){
						Param.imageBackground=Param.imageBackgroundHYZX;
					}else if("�̲�����".equals(text)){
						Param.imageBackground=Param.imageBackgroundLCQQ;
					}else if("ˮī�໨".equals(text)){
						Param.imageBackground=Param.imageBackgroundSMQH;
					}else if("����ͷ�".equals(text)){
						Param.imageBackground=Param.imageBackgroundWCBF;
					}else if("��ɫ֮��".equals(text)){
						Param.imageBackground=Param.imageBackgroundLSZL;
					}
					mainFrame.repaint();
					
					
					
				}
			});
		}
		
		JMenu menuHelp = new JMenu("����");
		
		menuHelp.add(menuItemRule);
		menuHelp.addSeparator();
		menuHelp.add(menuItemAbout);
		this.add(menuSet);
		this.add(menuHelp);
		
		menuItemParam.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new ParamJDialog(mainFrame);
				
			}
		});
		
		menuItemExit.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new ExitJDialog(mainFrame);
				
			
			}
			
		});
		
		menuItemScore.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {

				new ScoreJDialog(mainFrame);
				
			}
		});
		
		menuItemRule.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new RuleJDialog(mainFrame);			}
		
		
			
		});
	
		
		menuItemAbout.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				new AboutJDialog(mainFrame);
				
			}
		});
	}
	
	
	
}
