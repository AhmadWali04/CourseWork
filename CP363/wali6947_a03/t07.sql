SELECT b.broadDesc
FROM broad b
WHERE b.broadDesc NOT IN
	(SELECT mb.memberBroadBroadId
	FROM memberBroad mb)
ORDER BY b.broadDesc
