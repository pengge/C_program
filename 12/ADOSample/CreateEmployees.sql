USE [Northwind]
GO
/****** 对象:  Table [dbo].[Employees]    脚本日期: 12/08/2009 16:13:47 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Employees](
	[EMPLOYEEID] [int] IDENTITY(1,1) NOT NULL,
	[FirstName] [nvarchar](10) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[LastName] [nvarchar](20) COLLATE Chinese_PRC_CI_AS NOT NULL
) ON [PRIMARY]
