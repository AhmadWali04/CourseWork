SELECT 
    b.broadDesc AS broadExpertiseDescription,
    COUNT(mb.memberBroadBroadId) AS numberOfMembers
FROM 
    broad b
LEFT JOIN 
    memberBroad mb ON b.broadId = mb.memberBroadBroadId
GROUP BY 
    b.broadId
ORDER BY 
    broadExpertiseDescription
